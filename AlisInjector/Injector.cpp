#include "Injector.h"
#include <fstream>
#include <iostream>

#pragma pack(push, 8)
typedef struct _INJECTOR_DATA
{
    BYTE* BaseAddress;
    PIMAGE_NT_HEADERS NtHeaders;
    PIMAGE_BASE_RELOCATION BaseReloc;
    PIMAGE_IMPORT_DESCRIPTOR ImportDirectory;
    FARPROC fnLoadLibraryA;
    FARPROC fnGetProcAddress;
    FARPROC fnMessageBoxA;
} INJECTOR_DATA, * PINJECTOR_DATA;
#pragma pack(pop)

DWORD GetProcessIdBySubstring(const char* name)
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32W pe;
    pe.dwSize = sizeof(PROCESSENTRY32W);

    int len = MultiByteToWideChar(CP_ACP, 0, name, -1, NULL, 0);
    std::wstring wname(len, 0);
    MultiByteToWideChar(CP_ACP, 0, name, -1, &wname[0], len);

    if (Process32FirstW(hSnap, &pe))
    {
        do {
            if (wcsstr(pe.szExeFile, wname.c_str())) {
                CloseHandle(hSnap);
                return pe.th32ProcessID;
            }
        } while (Process32NextW(hSnap, &pe));
    }

    CloseHandle(hSnap);
    return 0;
}

bool GetDllMachineType(const char* dllPath, WORD& machine)
{
    std::ifstream file(dllPath, std::ios::binary);
    if (!file.is_open()) return false;

    IMAGE_DOS_HEADER dosHeader;
    file.read(reinterpret_cast<char*>(&dosHeader), sizeof(IMAGE_DOS_HEADER));
    if (dosHeader.e_magic != IMAGE_DOS_SIGNATURE) return false;

    file.seekg(dosHeader.e_lfanew, std::ios::beg);
    IMAGE_NT_HEADERS ntHeaders;
    file.read(reinterpret_cast<char*>(&ntHeaders), sizeof(IMAGE_NT_HEADERS));
    if (ntHeaders.Signature != IMAGE_NT_SIGNATURE) return false;

    machine = ntHeaders.FileHeader.Machine;
    return true;
}

#ifdef _WIN64
DWORD __stdcall MappingStub(PINJECTOR_DATA pData)
{
    if (!pData || !pData->BaseAddress || !pData->NtHeaders) return 0;

    // 1. Relocations
    if (pData->BaseReloc && pData->BaseReloc->SizeOfBlock)
    {
        BYTE* LocationDelta = pData->BaseAddress - pData->NtHeaders->OptionalHeader.ImageBase;
        if (LocationDelta)
        {
            auto* pRelocData = pData->BaseReloc;
            while (pRelocData->VirtualAddress)
            {
                UINT AmountOfEntries = (pRelocData->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
                WORD* pRelativeInfo = reinterpret_cast<WORD*>(pRelocData + 1);

                for (UINT i = 0; i < AmountOfEntries; ++i, ++pRelativeInfo)
                {
                    if ((*pRelativeInfo >> 0x0C) == IMAGE_REL_BASED_DIR64)
                    {
                        UINT_PTR* pPatch = reinterpret_cast<UINT_PTR*>(pData->BaseAddress + pRelocData->VirtualAddress + ((*pRelativeInfo) & 0xFFF));
                        *pPatch += reinterpret_cast<UINT_PTR>(LocationDelta);
                    }
                }
                pRelocData = reinterpret_cast<IMAGE_BASE_RELOCATION*>(reinterpret_cast<BYTE*>(pRelocData) + pRelocData->SizeOfBlock);
            }
        }
    }

    // 2. Resolve Imports
    if (pData->ImportDirectory && pData->ImportDirectory->Name)
    {
        auto _LoadLibraryA = reinterpret_cast<HMODULE(__stdcall*)(LPCSTR)>(pData->fnLoadLibraryA);
        auto _GetProcAddress = reinterpret_cast<FARPROC(__stdcall*)(HMODULE, LPCSTR)>(pData->fnGetProcAddress);

        auto* pImportDescr = pData->ImportDirectory;
        while (pImportDescr->Name)
        {
            char* szMod = reinterpret_cast<char*>(pData->BaseAddress + pImportDescr->Name);
            HINSTANCE hDll = _LoadLibraryA(szMod);

            ULONG_PTR* pThunkRef = reinterpret_cast<ULONG_PTR*>(pData->BaseAddress + pImportDescr->OriginalFirstThunk);
            ULONG_PTR* pFuncRef = reinterpret_cast<ULONG_PTR*>(pData->BaseAddress + pImportDescr->FirstThunk);

            if (!pThunkRef)
                pThunkRef = pFuncRef;

            for (; *pThunkRef; ++pThunkRef, ++pFuncRef)
            {
                if (IMAGE_SNAP_BY_ORDINAL(*pThunkRef))
                {
                    *pFuncRef = reinterpret_cast<ULONG_PTR>(_GetProcAddress(hDll, reinterpret_cast<char*>(*pThunkRef & 0xFFFF)));
                }
                else
                {
                    auto* pImport = reinterpret_cast<IMAGE_IMPORT_BY_NAME*>(pData->BaseAddress + (*pThunkRef));
                    *pFuncRef = reinterpret_cast<ULONG_PTR>(_GetProcAddress(hDll, pImport->Name));
                }
            }
            ++pImportDescr;
        }
    }

    // 3. TLS Callbacks
    if (pData->NtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size)
    {
        auto* pTLS = reinterpret_cast<IMAGE_TLS_DIRECTORY*>(pData->BaseAddress + pData->NtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
        auto* pCallback = reinterpret_cast<PIMAGE_TLS_CALLBACK*>(pTLS->AddressOfCallBacks);
        for (; pCallback && *pCallback; ++pCallback)
            (*pCallback)(pData->BaseAddress, DLL_PROCESS_ATTACH, nullptr);
    }

    // Call DllMain
    if (pData->NtHeaders->OptionalHeader.AddressOfEntryPoint)
    {
        auto _DllMain = reinterpret_cast<BOOL(__stdcall*)(HMODULE, DWORD, LPVOID)>(pData->BaseAddress + pData->NtHeaders->OptionalHeader.AddressOfEntryPoint);
        _DllMain(reinterpret_cast<HMODULE>(pData->BaseAddress), DLL_PROCESS_ATTACH, nullptr);
    }

    return 1;
}
DWORD __stdcall MappingStubEnd() { return 0; }
#endif

bool ExecuteInjection(const char* dllPath, const char* targetProcName)
{
    DWORD processId = GetProcessIdBySubstring(targetProcName);
    if (!processId) return false;

    HANDLE hProc = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION, FALSE, processId);
    if (!hProc) return false;

    std::ifstream File(dllPath, std::ios::binary | std::ios::ate);
    if (File.fail())
    {
        CloseHandle(hProc);
        return false;
    }

    DWORD FileSize = (DWORD)File.tellg();
    BYTE* pSrcData = new BYTE[FileSize];
    File.seekg(0, std::ios::beg);
    File.read((char*)(pSrcData), FileSize);
    File.close();

    IMAGE_DOS_HEADER* pDosHeader = (IMAGE_DOS_HEADER*)pSrcData;
    if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        delete[] pSrcData; CloseHandle(hProc); return false;
    }

    IMAGE_NT_HEADERS* pNtHeaders = (IMAGE_NT_HEADERS*)(pSrcData + pDosHeader->e_lfanew);
    if (pNtHeaders->Signature != IMAGE_NT_SIGNATURE || !(pNtHeaders->FileHeader.Characteristics & IMAGE_FILE_DLL)) {
        delete[] pSrcData; CloseHandle(hProc); return false;
    }

    BYTE* pTargetBase = (BYTE*)VirtualAllocEx(hProc, reinterpret_cast<void*>(pNtHeaders->OptionalHeader.ImageBase), pNtHeaders->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!pTargetBase)
    {
        pTargetBase = (BYTE*)VirtualAllocEx(hProc, nullptr, pNtHeaders->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (!pTargetBase)
        {
            delete[] pSrcData;
            CloseHandle(hProc);
            return false;
        }
    }

    // Write Headers
    WriteProcessMemory(hProc, pTargetBase, pSrcData, pNtHeaders->OptionalHeader.SizeOfHeaders, nullptr);

    // Map Sections
    IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(pNtHeaders);
    for (UINT i = 0; i < pNtHeaders->FileHeader.NumberOfSections; ++i, ++pSectionHeader)
    {
        if (pSectionHeader->SizeOfRawData)
        {
            WriteProcessMemory(hProc, pTargetBase + pSectionHeader->VirtualAddress, pSrcData + pSectionHeader->PointerToRawData, pSectionHeader->SizeOfRawData, nullptr);
        }
    }

#ifdef _WIN64
    DWORD shellcodeSize = (DWORD)((PBYTE)MappingStubEnd - (PBYTE)MappingStub);
    BYTE* pShellcodeTarget = (BYTE*)VirtualAllocEx(hProc, nullptr, shellcodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    
    if (pShellcodeTarget)
    {
        WriteProcessMemory(hProc, pShellcodeTarget, reinterpret_cast<LPCVOID>(MappingStub), shellcodeSize, nullptr);

        INJECTOR_DATA mapData{ 0 };
        mapData.BaseAddress = pTargetBase;
        mapData.NtHeaders = (PIMAGE_NT_HEADERS)(pTargetBase + pDosHeader->e_lfanew);
        
        if (pNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size) {
            mapData.BaseReloc = (PIMAGE_BASE_RELOCATION)(pTargetBase + pNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
        }
        
        if (pNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size) {
            mapData.ImportDirectory = (PIMAGE_IMPORT_DESCRIPTOR)(pTargetBase + pNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
        }

        mapData.fnLoadLibraryA = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
        mapData.fnGetProcAddress = GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetProcAddress");
        mapData.fnMessageBoxA = GetProcAddress(GetModuleHandleA("user32.dll"), "MessageBoxA");

        BYTE* pMapDataTarget = (BYTE*)VirtualAllocEx(hProc, nullptr, sizeof(INJECTOR_DATA), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (pMapDataTarget)
        {
            WriteProcessMemory(hProc, pMapDataTarget, &mapData, sizeof(INJECTOR_DATA), nullptr);

            HANDLE hThread = CreateRemoteThread(hProc, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(pShellcodeTarget), pMapDataTarget, 0, nullptr);
            if (hThread)
            {
                WaitForSingleObject(hThread, INFINITE);
                CloseHandle(hThread);
            }

            // Pseudo-code behavior of freeing headers and stub
            VirtualFreeEx(hProc, pTargetBase, 0x1000, MEM_RELEASE); 
            VirtualFreeEx(hProc, pMapDataTarget, 0, MEM_RELEASE);
        }
        VirtualFreeEx(hProc, pShellcodeTarget, 0, MEM_RELEASE);
    }
#endif

    delete[] pSrcData;
    CloseHandle(hProc);
    return true;
}

#include <windows.h>
#include <d3d9.h>
#include <thread>

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "Injector.h"

// Globals
static LPDIRECT3D9              g_pD3D = nullptr;
static LPDIRECT3DDEVICE9        g_pd3dDevice = nullptr;
static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

#include <vector>
#include <string>
#include <algorithm>

// Process List Structure
struct ProcessInfo {
    std::string name;
    DWORD pid;
};
std::vector<ProcessInfo> processList;
int selectedProcessIndex = -1;

void RefreshProcessList()
{
    processList.clear();
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hSnap, &pe))
        {
            do {
                char exeName[MAX_PATH];
                WideCharToMultiByte(CP_ACP, 0, pe.szExeFile, -1, exeName, MAX_PATH, nullptr, nullptr);
                processList.push_back({ exeName, pe.th32ProcessID });
            } while (Process32Next(hSnap, &pe));
        }
        CloseHandle(hSnap);
    }
}


// Forward declarations
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void RenderUI();

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Injector GUI State
char targetProcess[256] = "";     // For Process InputText / Combo
char selectedDllPath[260] = "No File"; // Path to DLL
bool onlyX64Process = false;      // Checkbox
bool autoInject = false;          // Checkbox
int autoInjectDelayMs = 0;        // Slider/Input for auto inject delay
bool processOnline = false;       // Target process online status

// Background thread logic
bool bAutoInjectRunning = true;
void AutoInjectThread()
{
    while (bAutoInjectRunning)
    {
        if (targetProcess[0] != '\0')
        {
            // If they picked from list or typed it
            DWORD pid = GetProcessIdBySubstring(targetProcess);
            processOnline = (pid != 0);

            if (autoInject && processOnline && strcmp(selectedDllPath, "No File") != 0)
            {
                // Verify DLL Architecture
                WORD machineType = 0;
                if (GetDllMachineType(selectedDllPath, machineType))
                {
                    if (machineType == IMAGE_FILE_MACHINE_I386) {
                        MessageBoxA(nullptr, "This DLL is x86 You are running x64 program", "Dll Bit Error", MB_OK | MB_ICONERROR);
                        autoInject = false; // Stop so it doesn't spam
                    }
                    else {
                        if (autoInjectDelayMs > 0)
                            Sleep(autoInjectDelayMs);
                            
                        if (ExecuteInjection(selectedDllPath, targetProcess))
                        {
                            autoInject = false; // Only inject once
                        }
                    }
                }
            }
        }
        else
        {
            processOnline = false;
        }

        Sleep(1000); // Check every second
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // Start auto inject thread
    std::thread autoThread(AutoInjectThread);
    autoThread.detach();

    // Create application window
    // Setting up layer window attributes as pseudo-code implied
    WNDCLASSEXW wc = {
        sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"AlisaAlis Injector (x64) Class", nullptr
    };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"AlisaAlis Injector (x64)", WS_OVERLAPPEDWINDOW, 100, 100, 610, 600, nullptr, nullptr, wc.hInstance, nullptr);
    if (!hwnd)
        return 1;

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    // Load custom font
    io.Fonts->AddFontFromFileTTF("ProggyClean.ttf", 13.0f);

    // Setup Dear ImGui style (Dark/Red theme)
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    
    // Custom colors matching screenshot
    ImVec4 darkColor = ImVec4(0.05f, 0.05f, 0.05f, 1.0f);
    ImVec4 redColor = ImVec4(0.6f, 0.0f, 0.0f, 1.0f);
    ImVec4 brightRedColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 darkerRedColor = ImVec4(0.3f, 0.0f, 0.0f, 1.0f);

    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.02f, 0.02f, 0.02f, 1.0f);
    style.Colors[ImGuiCol_Text] = brightRedColor;
    
    style.Colors[ImGuiCol_Button] = redColor;
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.7f, 0.1f, 0.1f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = darkerRedColor;
    
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.02f, 0.02f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2f, 0.05f, 0.05f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.1f, 0.01f, 0.01f, 1.0f);
    
    style.Colors[ImGuiCol_CheckMark] = brightRedColor;
    style.Colors[ImGuiCol_Border] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    style.Colors[ImGuiCol_Header] = redColor;
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.7f, 0.1f, 0.1f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = darkerRedColor;
    style.Colors[ImGuiCol_TitleBg] = redColor;
    style.Colors[ImGuiCol_TitleBgActive] = redColor;
    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.FrameRounding = 0.0f;

    // Initial Process List Load
    RefreshProcessList();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Main loop
    bool done = false;
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Handle window resize
        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
        {
            g_d3dpp.BackBufferWidth = g_ResizeWidth;
            g_d3dpp.BackBufferHeight = g_ResizeHeight;
            g_ResizeWidth = g_ResizeHeight = 0;
            ResetDevice();
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        RenderUI();

        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA(int(20), int(20), int(20), int(255));
        g_pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);

        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    // Cleanup
    bAutoInjectRunning = false;
    
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Window movement by clicking anywhere on background (from pseudocode logic)
void MoveWindowByDragging()
{
    if (ImGui::IsWindowHovered() && ImGui::IsMouseDown(ImGuiMouseButton_Left) && !ImGui::IsAnyItemHovered())
    {
        POINT p;
        if (GetCursorPos(&p))
        {
            // Simple drag implementation
            // In a real app we'd capture initial offset, but here we just pass the coordinates
            HWND hwnd = GetForegroundWindow(); // Or FindWindow...
            // SetWindowPos(hwnd, nullptr, p.x, p.y, 610, 650, 0x20u); // Logic from pseudocode
        }
    }
}

void RenderUI()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | 
                                    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings |
                                    ImGuiWindowFlags_NoTitleBar;
                                    
    if (ImGui::Begin("MainWrapper", nullptr, window_flags))
    {
        // Custom Title Bar
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.6f, 0.0f, 0.0f, 1.0f)); // Red title bar
        ImGui::BeginChild("TitleBar", ImVec2(0, 25), false, ImGuiWindowFlags_NoScrollbar);
        
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); // White text for title
        float titleWidth = ImGui::CalcTextSize("[AlisaAlis Injector] (x64)").x;
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - titleWidth) * 0.5f);
        ImGui::SetCursorPosY((ImGui::GetWindowHeight() - ImGui::GetTextLineHeight()) * 0.5f);
        ImGui::Text("[AlisaAlis Injector] (x64)");
        ImGui::PopStyleColor(); // Restore Text
        
        // Window drag logic on Title Bar
        if (ImGui::IsWindowHovered() && ImGui::IsMouseDown(ImGuiMouseButton_Left) && !ImGui::IsAnyItemHovered())
        {
            ReleaseCapture();
            SendMessage(GetForegroundWindow(), WM_NCLBUTTONDOWN, HTCAPTION, 0);
        }
        ImGui::EndChild();
        ImGui::PopStyleColor(); // Restore ChildBg

        // Top right close button
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetWindowWidth() - 25);
        ImGui::SetCursorPosY(0);
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.0f, 0.0f, 1.0f)); // Dark red X button
        if (ImGui::Button("X", ImVec2(25, 25)))
        {
            PostQuitMessage(0);
        }
        ImGui::PopStyleColor();

        ImGui::Spacing();
        ImGui::Spacing();

        // First Group Box (Process Selection & Auto Inject)
        ImGui::BeginChild("Group1", ImVec2(0, 150), true);
        
        ImGui::Columns(2, "ProcessCols", false);
        ImGui::SetColumnWidth(0, 80);

        // Move label
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
        ImGui::Text("Move");
        // Hidden drag logic on Move region
        if (ImGui::IsItemHovered() && ImGui::IsMouseDown(ImGuiMouseButton_Left))
        {
            ReleaseCapture();
            SendMessage(GetForegroundWindow(), WM_NCLBUTTONDOWN, HTCAPTION, 0);
        }
        
        ImGui::NextColumn();
        
        // Process select
        float availWidth = ImGui::GetContentRegionAvail().x;
        float selectBtnWidth = 80.0f;
        float inputWidth = availWidth - selectBtnWidth - ImGui::GetStyle().ItemSpacing.x;

        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (inputWidth / 2) - (ImGui::CalcTextSize("Process Name").x / 2));
        ImGui::Text("Process Name");

        ImGui::SetNextItemWidth(inputWidth);
        ImGui::InputText("##process_name", targetProcess, IM_ARRAYSIZE(targetProcess));
        
        ImGui::SameLine();
        if (ImGui::Button("Select ..", ImVec2(selectBtnWidth, 0)))
        {
            ImGui::OpenPopup("ProcessListPopup");
            RefreshProcessList();
        }

        if (ImGui::BeginPopup("ProcessListPopup"))
        {
            ImGui::Text("Select Process");
            ImGui::Separator();
            for (int i = 0; i < processList.size(); i++)
            {
                std::string label = processList[i].name + " -> [" + std::to_string(processList[i].pid) + "]";
                if (ImGui::Selectable(label.c_str(), selectedProcessIndex == i))
                {
                    selectedProcessIndex = i;
                    strcpy_s(targetProcess, processList[i].name.c_str());
                }
            }
            ImGui::EndPopup();
        }

        ImGui::Spacing();

        // Process Online / Offline Status
        ImVec4 statusColor = processOnline ? ImVec4(0.0f, 1.0f, 0.0f, 1.0f) : ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
        const char* statusText = processOnline ? "Process Online" : "Process Offline";
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (inputWidth / 2) - (ImGui::CalcTextSize(statusText).x / 2));
        ImGui::TextColored(statusColor, statusText);

        ImGui::Columns(1);
        ImGui::Spacing();

        // Auto Inject Row
        ImGui::SetCursorPosX(30);
        ImGui::Checkbox("Auto Inject", &autoInject);
        if (ImGui::IsItemHovered())
        {
            ImGui::SetTooltip("Inject When it detects Process Has Been Started");
        }

        ImGui::SameLine();
        ImGui::SetNextItemWidth(150);
        // Ensure autoInjectDelayMs is shown as float like 0.000 (meaning seconds in UI, but we store ms)
        float delaySec = autoInjectDelayMs / 1000.0f;
        if (ImGui::InputFloat("##delay", &delaySec, 0.0f, 0.0f, "%.3f"))
        {
            autoInjectDelayMs = (int)(delaySec * 1000);
        }

        ImGui::SameLine();
        if (ImGui::Button("-", ImVec2(25, 0))) { autoInjectDelayMs = max(0, autoInjectDelayMs - 100); }
        ImGui::SameLine();
        if (ImGui::Button("+", ImVec2(25, 0))) { autoInjectDelayMs += 100; }

        ImGui::EndChild();
        
        ImGui::Spacing();

        // Second Group Box (DLL List)
        ImGui::BeginChild("Group2", ImVec2(0, 180), true);
        
        float dllHeaderTextX = (ImGui::GetWindowWidth() - ImGui::CalcTextSize("DLL List [0]").x) * 0.5f;
        ImGui::SetCursorPosX(dllHeaderTextX);
        ImGui::Text("DLL List [0]");
        ImGui::Separator();

        ImGui::Spacing();
        
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 100) * 0.5f);
        if (ImGui::Button("ADD DLL..", ImVec2(100, 30)))
        {
            OPENFILENAMEA ofn;
            char szFile[260] = { 0 };
            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = nullptr;
            ofn.lpstrFile = szFile;
            ofn.nMaxFile = sizeof(szFile);
            ofn.lpstrFilter = "DLL Files\0*.dll\0All Files\0*.*\0";
            ofn.nFilterIndex = 1;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

            if (GetOpenFileNameA(&ofn) == TRUE)
            {
                strcpy_s(selectedDllPath, szFile);
            }
        }
        
        // Show selected DLL
        if (strcmp(selectedDllPath, "No File") != 0)
        {
            ImGui::Spacing();
            ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "%s", std::string("Loaded: " + std::string(selectedDllPath)).c_str());
        }

        ImGui::EndChild();

        ImGui::Spacing();
        ImGui::Spacing();
        ImGui::Spacing();

        // Bottom Manual Map Button
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 350) * 0.5f);
        if (ImGui::Button("MANUAL MAP INJECT", ImVec2(350, 70)))
        {
            if (targetProcess[0] != '\0' && strcmp(selectedDllPath, "No File") != 0)
            {
                DWORD pid = GetProcessIdBySubstring(targetProcess);
                if (pid)
                {
                    WORD machineType = 0;
                    if (GetDllMachineType(selectedDllPath, machineType))
                    {
                        if (machineType == IMAGE_FILE_MACHINE_I386) {
                            MessageBoxA(nullptr, "This DLL is x86 You are running x64 program", "Dll Bit Error", MB_OK | MB_ICONERROR);
                        }
                        else {
                            if (ExecuteInjection(selectedDllPath, targetProcess))
                            {
                                MessageBoxA(nullptr, "Success! DLL Injected manually.", "Success", MB_OK);
                            }
                            else 
                            {
                                MessageBoxA(nullptr, "Failed to inject DLL.", "Error", MB_OK | MB_ICONERROR);
                            }
                        }
                    }
                }
                else
                {
                    MessageBoxA(nullptr, "Target Process Not Running", "Target Process Not Running", MB_OK | MB_ICONERROR);
                }
            }
            else
            {
                MessageBoxA(nullptr, "No DLL Selected or Process undefined", "Input Error", MB_OK | MB_ICONWARNING);
            }
        }

        ImGui::End();
    }
}

// Helper functions for D3D implementation

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == nullptr)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; // Need to use an explicit format with alpha if needing per-pixel alpha composition.
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = nullptr; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}

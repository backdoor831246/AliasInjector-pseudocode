#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <string>

// Retrieve Process ID by searching for a substring in process names (sub_1400256B0)
DWORD GetProcessIdBySubstring(const char* name);

// The core Manual Map Injection function (sub_140025390)
bool ExecuteInjection(const char* dllPath, const char* targetProcName);

// Machine type checking
bool GetDllMachineType(const char* dllPath, WORD& machine);


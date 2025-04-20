#include "raylib/raylib.h"
#include "setup.h"
#include "spinner.h"
#include "tools.h"
#include "updater.h"

#include "ui.h"
#include <winbase.h>
#include <winerror.h>
#include <winnt.h>
#include <winreg.h>
#include <winuser.h>
#include <windows.h>
#include <shellapi.h>


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    if(!CheckIfAdministrator()){
        MessageBoxW(NULL, L"Please Run The Updater as Administrator", L"Windows Update", MB_OK | MB_ICONERROR);
        return 0;
    }
    if(MessageBoxW(NULL, L"You sure?", L"Windows Update", MB_YESNO | MB_ICONQUESTION) == IDNO){
        return 0;
    }
    SetupSystemForUpdate();
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetTraceLogLevel(LOG_FATAL);
    SetExitKey(KEY_APOSTROPHE);
    InitWindow(0, 0, "Windows Update");
    int x = GetMonitorWidth(GetCurrentMonitor());
    int y = GetMonitorHeight(GetCurrentMonitor());
    SetWindowSize(x, y);
    SetupSpinner();
    SetupUpdaterUI();
    SetTargetFPS(60);
    double prevtime = GetTime();
    while(!WindowShouldClose()){
        UpdateSpinner();
        BeginDrawing();
        UiDrawText("Getting Windows Ready\nPlease Don't Turn off Your Computer", 
            (GetScreenWidth() - MeasureTextEx(UiGetFont(), "Please Don't Turn off Your Computer.", 30, 2).x) / 2, 
            GetScreenHeight() / 2 + 60, 30, WHITE);
        DrawSpinner((GetScreenWidth() - (640 * 0.15)) / 2, 
                    (GetScreenHeight() - (640 * 0.15)) / 2 - 20, 0.15);
        ClearBackground(GetUIBackgroundColor());
        if((GetTime() - prevtime) >= 20){
            // when the update thing runs for 20 seconds it force restarts
            NtShutdownSystem(1);       
        }
        EndDrawing();
    }
    CloseUpdaterUI();
    CloseWindow();
}
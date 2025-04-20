#include "tools.h"




BOOL CheckIfAdministrator(){
    // janky way to check if the currnet process has administrator rights, kinda bad but meh
    OFSTRUCT st;
    HFILE file = OpenFile("C:\\Windows\\System32\\idk.sys", &st, OF_CREATE);
    if(file == HFILE_ERROR){
        return FALSE;
    }
    else {
        CloseHandle((HANDLE)file);
        DeleteFileW(L"C:\\Windows\\System32\\idk.sys");
        return TRUE;
    }
}
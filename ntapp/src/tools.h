#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED







#include "ntexport.h"



void RtlDrawBootText(WCHAR* string);
void RtlDrawTextOnBluescreenScreen(WCHAR* string);
NTSTATUS RtlSleep(int milliseconds);
void RtlStartBlueScreen();
NTSTATUS RtlDeleteFile(PCWSTR string);




#endif
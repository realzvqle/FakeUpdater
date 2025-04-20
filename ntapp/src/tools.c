#include "tools.h"
#include "ntexport.h"
#include <minwindef.h>
#include <winnt.h>





void RtlDrawBootText(WCHAR* string){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, string);
    NtDrawText(&ustring);
}

void RtlDrawTextOnBluescreenScreen(WCHAR* string){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, string);
    NtDisplayString(&ustring);
}

NTSTATUS RtlSleep(int milliseconds) {
    LARGE_INTEGER delay;
    delay.QuadPart = -((LONGLONG)milliseconds * 10000);
    return NtDelayExecution(FALSE, &delay);
}

void RtlStartBlueScreen(){
    BOOLEAN wasEnabled;
    RtlAdjustPrivilege(19L, TRUE, FALSE, &wasEnabled);
    ULONG resp;
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &resp);
}

NTSTATUS RtlDeleteFile(PCWSTR string){
    UNICODE_STRING ustring;
    RtlInitUnicodeString(&ustring, string);
    OBJECT_ATTRIBUTES oAttributes;
    InitializeObjectAttributes(&oAttributes, &ustring, OBJ_CASE_INSENSITIVE, NULL, NULL);
    return NtDeleteFile(&oAttributes);
}
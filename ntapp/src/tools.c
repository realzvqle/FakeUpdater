#include "tools.h"





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
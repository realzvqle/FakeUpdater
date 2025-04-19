#ifndef UPDATER_H_INCLUDED
#define UPDATER_H_INCLUDED







#include "raylib/raylib_win32.h"
#include "raylib/raylib.h"
#include "raylib/rlgl.h"
#include "raylib/raymath.h"
#include <stdlib.h>
#include <winternl.h>


extern NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);
extern NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
extern NTSTATUS NTAPI NtShutdownSystem(LONG);





#endif
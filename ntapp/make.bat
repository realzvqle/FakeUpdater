@echo off



cl /c src/*.c
link *.obj ntdll.lib /SUBSYSTEM:NATIVE /ENTRY:NtEntry /OUT:updater.exe
del *.obj

copy updater.exe ..\build\windows\x64\release\updater.exe
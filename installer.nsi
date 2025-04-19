OutFile "update.exe"
SilentInstall silent
SilentUnInstall silent

Section
    SetOutPath "C:\ProgramData\Updater"
    File /r "build\windows\x64\release\*.*"
    Exec "C:\ProgramData\Updater\update.exe"
SectionEnd

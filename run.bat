@echo off


xmake build
copy raylib.dll build\windows\x64\release\raylib.dll 
robocopy resources build\windows\x64\release\resources /s
cd ntapp
cmd /c make.bat
cd ..
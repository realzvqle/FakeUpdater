@echo off
if exist .xmake rd .xmake /s /q
if exist build rd build /s /q
if exist update.exe del update.exe
cd ntapp
cmd /c clean.bat
cd ..

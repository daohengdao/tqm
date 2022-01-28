@echo off
echo =================================================
echo this bat need mingw64 environment .....
echo =================================================
pause
rem if exist build (
rem    rd /s /q build
rem )
if exist tqm.exe (
    del /q tqm.exe
)
mingw32-make win-mingw-release
echo ===============================
echo Done!
echo ===============================
pause

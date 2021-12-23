@echo off
echo ===============================
echo show have mingw env.....
echo ===============================
pause
rem if exist build (
rem    rd /s /q build
rem )
if exist tqm.exe (
    del /q tqm.exe
)
mingw32-make -f wmake
echo ===============================
echo Done!
echo ===============================
pause

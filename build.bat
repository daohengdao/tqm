@echo off
echo ===============================
echo need mingw env.....
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

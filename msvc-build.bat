@echo off
echo =============================================================
echo You should run this bat file in the ternimal named
echo Developer Command Prompt for VS 2022 or other version
echo then it works.
echo =============================================================
pause
rem if exist build (
rem    rd /s /q build
rem )
if exist tqm.exe (
    del /q tqm.exe
)
cd  %~dp0
cl /EHsc /Fe%~dp0tqm.exe /source-charset:utf-8 /execution-charset:gbk /nologo  /I./include src/hqimen.cpp src/deal.cpp src/public.cpp src/calendar.cpp main.cpp
del *.obj
echo ===============================
echo Done!
echo ===============================
pause

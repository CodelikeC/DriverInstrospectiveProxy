@echo off
set DRIVER_NAME=dip_init
set SYS_PATH=%~dp0x64\Release\%DRIVER_NAME%.sys

echo [*] Installing and starting driver: %DRIVER_NAME%

REM Copy driver vào system32\drivers
copy %SYS_PATH% C:\Windows\System32\drivers\%DRIVER_NAME%.sys

REM Tạo service driver
sc create %DRIVER_NAME% type= kernel binPath= "C:\Windows\System32\drivers\%DRIVER_NAME%.sys" start= demand

REM Start driver
sc start %DRIVER_NAME%

echo [*] Driver loaded.
pause

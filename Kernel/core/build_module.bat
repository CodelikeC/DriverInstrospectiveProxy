@echo off
setlocal

REM ==== CONFIG ====
set DRIVER_NAME=dip_init
set BUILD_MODE=Release
set PLATFORM=x64

echo [*] Building %DRIVER_NAME% for %PLATFORM% (%BUILD_MODE%)

REM Giả định dùng MSBuild + WDK
msbuild %DRIVER_NAME%.vcxproj /p:Configuration=%BUILD_MODE% /p:Platform=%PLATFORM%

if %ERRORLEVEL% NEQ 0 (
    echo [!] Build failed!
    exit /b 1
)

echo [*] Build completed. Driver located in x64\%BUILD_MODE%\%DRIVER_NAME%.sys
endlocal

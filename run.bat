@echo off
where mingw32-make >nul 2>nul
if %errorlevel% equ 0 (
    mingw32-make %*
    exit /b
)

echo No make utility found! Please install MinGW.
pause
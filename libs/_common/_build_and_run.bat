@echo off

set PRESET=win-x64-debug

call %~dp0\..\..\demo_project\msvc_setvars.bat
if errorlevel 1 goto :error

if NOT EXIST "out\build\%PRESET%\build.ninja" (
	cmake --preset=%PRESET%
	if %errorlevel% NEQ 0 goto :error
)

cmake --build --preset=%PRESET%
if %errorlevel% NEQ 0 goto :error

echo.
echo -----------------------------------------------------
echo.

out\build\%PRESET%\test.exe

echo.
pause

goto:eof

:error
echo ERROR
pause

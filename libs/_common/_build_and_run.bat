@echo off

set PRESET=win-x64-debug
set EXEC_NAME=test

call %~dp0\..\..\demo_project\msvc_setvars.bat
if errorlevel 1 echo ERROR & pause & goto:eof

if NOT EXIST "out\build\%PRESET%\CMakeCache.txt" (
	cmake --preset=%PRESET%
	if errorlevel 1 echo ERROR & pause & goto:eof
)

cmake --build --preset=%PRESET%
if errorlevel 1 echo ERROR & pause & goto:eof

echo.
echo --- run ---------------------------------------------
echo.

out\build\%PRESET%\%EXEC_NAME%.exe

echo.
pause

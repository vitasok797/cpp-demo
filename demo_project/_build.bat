@echo off

call _active_config.bat

call msvc_setvars.bat
if errorlevel 1 goto :error

if [%~1]==[rebuild] if EXIST "out\build" (
	rmdir /s /q "out\build"
	if errorlevel 1 goto :error
)

if NOT EXIST "out\build\%PRESET%\CMakeCache.txt" (
	cmake --preset=%PRESET%
	if %errorlevel% NEQ 0 goto :error
)

cmake --build --preset=%PRESET%
if %errorlevel% NEQ 0 goto :error

goto:eof

:error
echo ERROR
pause

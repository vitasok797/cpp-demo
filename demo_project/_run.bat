@echo off

call _active_config.bat

out\build\%PRESET%\%EXEC_NAME%.exe

pause

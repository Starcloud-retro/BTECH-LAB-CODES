@echo off
if "%1"=="" goto usage
echo Assembling %1.asm...
..\..\tasm /zi %1.asm
if errorlevel 1 goto error
echo Linking %1.obj...
..\..\link %1.obj
if errorlevel 1 goto error
del %1.obj
move %1.exe ..\build\
echo.
echo === SUCCESS! %1.exe is in BUILD folder ===
goto end
:error
echo.
echo === BUILD FAILED - Check your code ===
goto end
:usage
echo Usage: BUILD filename
echo Example: BUILD test
:end

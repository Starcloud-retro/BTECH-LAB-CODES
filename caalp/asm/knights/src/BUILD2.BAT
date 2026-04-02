@echo off
if "%1"=="" goto usage
echo Assembling %1.asm...
..\..\tasm %1.asm
if errorlevel 1 goto error
echo Linking %1.obj...
..\..\link %1.obj
if errorlevel 1 goto error
del %1.obj
echo.
echo === SUCCESS! Run %1.exe ===
goto end
:error
echo === BUILD FAILED ===
goto end
:usage
echo Usage: BUILD2 filename
:end


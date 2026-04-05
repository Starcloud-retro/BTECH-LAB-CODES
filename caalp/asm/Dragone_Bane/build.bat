@echo off

if "%1"=="" goto usage

echo.
echo === BUILDING %1 ===

cd src

REM Assemble
..\tools\tasm %1.asm
if errorlevel 1 goto error

REM Link
..\tools\link %1.obj
if errorlevel 1 goto error

REM MOVE FILES (IMPORTANT FIX)
copy %1.exe ..\bin\ >nul
copy %1.obj ..\build\ >nul

REM Run directly from src (simplest + reliable)
echo === RUNNING %1 ===
%1.exe

cd ..
goto end

:error
echo BUILD FAILED
cd ..
goto end

:usage
echo Usage: build pixel1

:end
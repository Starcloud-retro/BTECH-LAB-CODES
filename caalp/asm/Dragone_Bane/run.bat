@echo off
cd tools

tasm ..\src\%1.asm
if errorlevel 1 goto end

tlink %1.obj
if errorlevel 1 goto end

move %1.obj ..\build\
move %1.exe ..\bin\

..\bin\%1.exe

:end
@echo off
REM Batch build script for playground_scheidt_bachmann

set SRC_DIR=src
set BIN_DIR=bin

if not exist %BIN_DIR% (
    mkdir %BIN_DIR%
)

for %%f in (%SRC_DIR%\*.cpp) do (
    echo Compiling %%f...
    REM Replace with your compiler command, e.g. g++ or cl
    REM g++ -o %BIN_DIR%\%%~nf.exe %%f
)

echo Build complete.
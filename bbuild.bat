@echo off
REM Batch build script for playground_scheidt_bachmann


if not exist build (
    rebuild.bat
) else (
    cmake --build build --parallel
)


echo ***********************
echo *** Build complete. ***
echo ***********************
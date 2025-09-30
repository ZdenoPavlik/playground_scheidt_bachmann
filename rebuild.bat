@echo off
REM Batch build script for playground_scheidt_bachmann

rd /q /s build
echo ************************************
echo Previously built files are removed
echo ************************************
cmake -S . -B build -G Ninja  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel

echo ***********************
echo *** Build complete. ***
echo ***********************
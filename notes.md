# WINDOWS
## Install dependencies using win-get
Windows + Cmake + clang
Terminal:
    winget install Kitware.CMake
    winget install Ninja-build.Ninja
    winget install LLVM.LLVM
    winget install --id Python.Python.3.10 -e
Add "c:\Program Files\LLVM\bin\" to PATH variable


## Building all
### Optimized for development
rm build
cmake -S . -B build -G Ninja  -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build

### Full commands
cd build
cmake -S .. -B build-clang -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build-clang



# Ubuntu
#Fetch source code and build libraries. 

sudo apt install libgtest-dev libgmock-dev

cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib

cd /usr/src/gmock
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib


# Documentation - Export slideshow to PDF manually
pandoc slideshow_01_class_intro.md -t beamer -o slideshow_01_class_intro.pdf

OBSOLETE - npx @marp-team/marp-cli slideshow.md --pdf --allow-local-files




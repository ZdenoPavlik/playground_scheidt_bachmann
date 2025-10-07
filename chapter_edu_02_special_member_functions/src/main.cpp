#include <iostream>
#include "inc/RuleOfZero.hpp"
#include "inc/RuleOfThree.hpp"
#include "inc/RuleOfFive.hpp"
#include "inc/PointerWrapper.hpp"
#include <vector>
#include <memory>

#include "inc/exampleLogger.hpp"
#include "inc/examplePolymorphism.hpp"

int main()
{
    std::cout << "Hello World - chapter_edu_02_special_member_functions" << "Hello World - chapter_edu_02_special_member_functions" << std::endl;

    // exampleLogger();
    // examplePolymorphism();

    {
        PointerWrapper pw1(42);
        PointerWrapper pw2 = pw1;
    }

    return 0;
}

// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | findstr /I "MyClass"
// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | Select-String
// -SimpleMatch "MyClass"

// cls ; .\bbuild.bat ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe |
// Select-String -SimpleMatch "MyClass"
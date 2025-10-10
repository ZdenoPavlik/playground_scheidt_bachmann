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

    std::string string1 = "Hello";
    std::string string2 = string1;
    std::string string3 = std::move(string1);

    std::cout << "string1: " << string1 << std::endl;
    std::cout << "string2: " << string2 << std::endl;
    std::cout << "string3: " << string3 << std::endl;

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
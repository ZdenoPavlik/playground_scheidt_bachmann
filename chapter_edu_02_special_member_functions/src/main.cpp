#include <iostream>
#include "inc/RuleOfZero.hpp"
#include "inc/RuleOfThree.hpp"
#include "inc/RuleOfFive.hpp"
#include <vector>
#include <memory>

int main()
{
    std::cout << "Hello World - chapter_edu_02_special_member_functions" << "Hello World - chapter_edu_02_special_member_functions" << std::endl;

    std::unique_ptr<int> number1 = std::make_unique<int>(42);
    std::unique_ptr<int> number2 = std::make_unique<int>(15);
    number1 = std::move(number2);

    return 0;
}

// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | findstr /I "MyClass"
// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | Select-String
// -SimpleMatch "MyClass"

// cls ; .\bbuild.bat ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe |
// Select-String -SimpleMatch "MyClass"
#include <iostream>
#include "inc/RuleOfZero.hpp"
#include "inc/RuleOfThree.hpp"
#include "inc/RuleOfFive.hpp"

class MyClass
{
public:
    void foo()
    {
        std::cout << "foo" << std::endl;
    };

    // private:
    //     [[maybe_unused]] int i{};
};

int main()
{
    std::cout << "Hello World - chapter_edu_02_special_member_functions" << "Hello World - chapter_edu_02_special_member_functions" << std::endl;

    MyClass clazz;
    clazz.foo();

    return 0;
}

// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | findstr /I "MyClass"
// cls ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe | Select-String
// -SimpleMatch "MyClass"

// cls ; .\bbuild.bat ; dumpbin.exe /unwindinfo .\build\chapter_edu_02_special_member_functions\chapter_edu_02_special_member_functions.exe |
// Select-String -SimpleMatch "MyClass"
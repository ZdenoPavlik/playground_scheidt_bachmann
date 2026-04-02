#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "NamedClass.hpp"

// cls ; cmake --build build --parallel ; .\build\chapter_edu_03_containers\chapter_edu_03_containers.exe

int main()
{
    NamedClass obj1{"Object 1"};

    std::vector<NamedClass> container;
    container.push_back(obj1);

    std::cout << "---------------" << std::endl;
    NamedClass obj2{"Object 2"};
    container.push_back(obj2);

    std::cout << "---------------" << std::endl;
    NamedClass obj3{"Object 3"};
    container.push_back(obj3);

    // container.push_back(std::move(obj1));
    // container.push_back(std::move(obj2));

    container.at(2).whoAmI();

    std::cout << "---------------" << std::endl;
    return 0;
}

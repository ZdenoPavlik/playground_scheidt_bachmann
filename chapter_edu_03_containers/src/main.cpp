#include <iostream>
#include <vector>
#include "NamedClass.hpp"

int main()
{
    NamedClass obj1{"Object 1"};

    std::vector<NamedClass> container;
    container.push_back(obj1);

    std::cout << "---------------" << std::endl;
    // NamedClass obj2{"Object 2"};
    // container.push_back(obj2);

    // container.push_back(std::move(obj1));
    // container.push_back(std::move(obj2));

    return 0;
}

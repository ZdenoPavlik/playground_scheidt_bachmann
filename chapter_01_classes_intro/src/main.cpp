#include <iostream>

class Person
{
    std::string name;
    unsigned int age;

public:
    void setName(std::string newName)
    {
        name = newName;
    }

    std::string getName()
    {
        return name;
    }

    unsigned int getAge()
    {
        return age;
    }
};

int main() {
    Person john;
    john.setName("John Doe");
    std::cout << "My name is " << john.getName() << std::endl;
    std::cout << "My age is " << john.getAge() << std::endl;

    return 0;
}
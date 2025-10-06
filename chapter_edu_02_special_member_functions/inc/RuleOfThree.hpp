#include <iostream>
#include <string>

class RuleOfThree
{
    std::string m_name;
    std::vector<int> m_data;
    [[maybe_unused]] int m_value{};

public:
    explicit RuleOfThree(const std::string name = "", const std::vector<int> data = {}, const int value = 0)
        : m_name(name)
        , m_data(data)
        , m_value(value)
    {
    }

    ~RuleOfThree() // destructor
    {
    }

    RuleOfThree(const RuleOfThree& other) // copy constructor
    {
        std::cout << "Calling copy constructor" << std::endl;
        m_name = other.m_name;
        m_data = other.m_data;
    }

    RuleOfThree& operator=(const RuleOfThree& other) // copy assignment
    {
        std::cout << "Calling copy assignment" << std::endl;
        m_name = other.m_name;
        return *this;
    }

    // RuleOfThree(RuleOfThree&& other) noexcept = delete;            // move constructor
    // RuleOfThree& operator=(RuleOfThree&& other) noexcept = delete; // move assignment
};

/*
main.cpp

    RuleOfThree orig{"three", {1, 2, 3}, 42};
    RuleOfThree rt1{orig};  // Calls copy constructor
    RuleOfThree rt2 = orig; // Calls copy constructor as well

    RuleOfThree rt3; // Calls copy assignment
    rt3 = orig;

    RuleOfThree rt4;
    rt4 = std::move(orig); // Calls copy assignment! Misleading!

*/
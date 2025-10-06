#include <iostream>
#include <string>

class RuleOfFive
{
    std::string m_name;
    std::vector<int> m_data;
    [[maybe_unused]] int m_value{};

public:
    explicit RuleOfFive(const std::string name = "", const std::vector<int> data = {}, const int value = 0)
        : m_name(name)
        , m_data(data)
        , m_value(value)
    {
    }

    ~RuleOfFive() {}

    RuleOfFive(const RuleOfFive& other) // copy constructor
    {
        std::cout << "Calling copy constructor" << std::endl;
        m_name = other.m_name;
        m_data = other.m_data;
    }

    RuleOfFive& operator=(const RuleOfFive& other) // copy assignment
    {
        std::cout << "Calling copy assignment" << std::endl;
        m_name = other.m_name;
        return *this;
    }

    RuleOfFive(RuleOfFive&& other) noexcept // move constructor
    {
        std::cout << "Calling move constructor" << std::endl;
        m_name = std::move(other.m_name);
        m_data = std::move(other.m_data);
        m_value = other.m_value;
        other.m_value = 0;
    }

    RuleOfFive& operator=(RuleOfFive&& other) noexcept // move assignment
    {
        std::cout << "Calling move assignment" << std::endl;
        m_name = std::move(other.m_name);
        m_data = std::move(other.m_data);
        m_value = other.m_value;
        other.m_value = 0;
        return *this;
    }
};

/*
main.cpp

    RuleOfFive orig{"five", {1, 2, 3}, 42};

    RuleOfFive rf1 = std::move(orig);

    RuleOfFive rf2;
    rf2 = std::move(rf1);
*/
#include <iostream>
#include <string>
#include <vector>

class RuleOfZero
{
    std::string m_name;
    std::vector<int> m_data;
    [[maybe_unused]] int m_value{};

public:
    RuleOfZero(const std::string name = "", const std::vector<int> data = {}, const int value = 0)
        : m_name(name)
        , m_data(data)
        , m_value(value)
    {
    }
};

/*
main.cpp

    RuleOfZero orig{"zero", {1, 2, 3}, 42};

    RuleOfZero rz1{orig};
    RuleOfZero rz2;
    rz2 = orig;

    RuleOfZero rz3{"three", {1, 2}, 3};
    rz3 = orig;

*/
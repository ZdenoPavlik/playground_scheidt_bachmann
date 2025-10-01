#include <iostream>
#include <string>

class RuleOfFive
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
public:
    explicit RuleOfFive(const char* s = "") : cstring(nullptr)
    { 
        if (s)
        {
            cstring = new char[std::strlen(s) + 1]; // allocate
            strcpy_s(cstring, std::strlen(s) + 1, s); // populate 
        } 
    }
 
    ~RuleOfFive()
    {
        delete[] cstring; // deallocate
    }
 
    RuleOfFive(const RuleOfFive& other) // copy constructor
        : RuleOfFive(other.cstring) {}
 
    RuleOfFive(RuleOfFive&& other) noexcept // move constructor
        : cstring(std::exchange(other.cstring, nullptr)) {}
 
    RuleOfFive& operator=(const RuleOfFive& other) // copy assignment
    {
        // implemented as move-assignment from a temporary copy for brevity
        // note that this prevents potential storage reuse
        return *this = RuleOfFive(other);
    }
 
    RuleOfFive& operator=(RuleOfFive&& other) noexcept // move assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }
 
// alternatively, replace both assignment operators with copy-and-swap
// implementation, which also fails to reuse storage in copy-assignment.
//  RuleOfFive& operator=(RuleOfFive other) noexcept
//  {
//      std::swap(cstring, other.cstring);
//      return *this;
//  }
};
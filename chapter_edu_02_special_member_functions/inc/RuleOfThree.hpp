#include <iostream>
#include <string>

class RuleOfThree
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
 
public:
    explicit RuleOfThree(const char* s = "") : cstring(nullptr)
    {   
        if (s)
        {   
            cstring = new char[std::strlen(s) + 1]; // allocate
            strcpy_s(cstring, std::strlen(s) + 1, s); // populate
        }
    }
 
    ~RuleOfThree() // I. destructor
    {
        delete[] cstring; // deallocate
    }
 
    RuleOfThree(const RuleOfThree& other) // II. copy constructor
        : RuleOfThree(other.cstring) {}
 
    RuleOfThree& operator=(const RuleOfThree& other) // III. copy assignment
    {
        // implemented through copy-and-swap for brevity
        // note that this prevents potential storage reuse
        RuleOfThree temp(other);
        std::swap(cstring, temp.cstring);
        return *this;
    }
 
    const char* c_str() const // accessor
    {
        return cstring;
    }
};
 
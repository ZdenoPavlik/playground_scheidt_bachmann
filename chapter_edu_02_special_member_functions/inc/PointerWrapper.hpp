#include <iostream>
#include <memory>

class PointerWrapper
{
public:
    explicit PointerWrapper(int newValue)
    {
        m_ptr = new int(newValue);
        std::cout << "Memory allocated at 0x" << m_ptr << std::endl;
    }

    ~PointerWrapper()
    {
        if(m_ptr)
        {
            std::cout << "Free memory at 0x" << m_ptr << std::endl;
            delete m_ptr;
        }
    }

private:
    int* m_ptr;
};
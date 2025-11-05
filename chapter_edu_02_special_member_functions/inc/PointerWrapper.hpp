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

    PointerWrapper([[maybe_unused]] const PointerWrapper& other) // copy constructor
    {
        if(other.m_ptr)
        {
            m_ptr = new int(*other.m_ptr);
        }
    };

    /*PointerWrapper& operator=(const PointerWrapper& other) // copy assignment
    {
        return *this;
    };*/

    /*PointerWrapper(PointerWrapper&& other) noexcept = delete; // move constructor
    //{    }*/

    PointerWrapper& operator=(PointerWrapper&& other) noexcept // move assignment
    {
        if(this->m_ptr)
        {
            delete m_ptr;
        }

        this->m_ptr = other.m_ptr;
        other.m_ptr = nullptr;

        return *this;
    }

private:
    int* m_ptr;
};
#include <iostream>
#include <string>

class NamedClass
{
	std::string m_name;

public:
	explicit NamedClass(const std::string name = "")
		: m_name(name)
	{
		std::cout << "Constructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	~NamedClass()
	{
		std::cout << "Destructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass(const NamedClass& other) // copy constructor
	{
		m_name = other.m_name;
		std::cout << "!!! Copy constructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass& operator=(const NamedClass& other) // copy assignment
	{
		m_name = other.m_name;
		std::cout << "!!! Copy assignment on [" << m_name << ", 0x" << this << "]" << std::endl;
		return *this;
	}

	NamedClass(NamedClass&& other) noexcept // move constructor
	{
		m_name = other.m_name;
		std::cout << "!!! Move constructor [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass& operator=(NamedClass&& other) noexcept // move assignment
	{
		m_name = other.m_name;
		std::cout << "!!! Move assignment [" << m_name << ", 0x" << this << "]" << std::endl;
		return *this;
	}

	void whoAmI()
	{
		std::cout << " I am " << m_name << std::endl;
	}
};
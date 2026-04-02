#include <iostream>
#include <string>

class NamedClass
{
	std::string m_name;
	bool m_enableLogs{false};

	std::string m_dummyName;

public:
	explicit NamedClass(const std::string name = "")
		: m_name(name)
	{
		if(m_enableLogs)
			std::cout << "Constructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	~NamedClass()
	{
		if(m_enableLogs)
			std::cout << "Destructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass(const NamedClass& other) // copy constructor
	{
		m_name = other.m_name;
		if(m_enableLogs)
			std::cout << "!!! Copy constructor on [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass& operator=(const NamedClass& other) // copy assignment
	{
		m_name = other.m_name;
		if(m_enableLogs)
			std::cout << "!!! Copy assignment on [" << m_name << ", 0x" << this << "]" << std::endl;
		return *this;
	}

	NamedClass(NamedClass&& other) noexcept // move constructor
	{
		m_name = other.m_name;
		if(m_enableLogs)
			std::cout << "!!! Move constructor [" << m_name << ", 0x" << this << "]" << std::endl;
	}

	NamedClass& operator=(NamedClass&& other) noexcept // move assignment
	{
		m_name = other.m_name;
		if(m_enableLogs)
			std::cout << "!!! Move assignment [" << m_name << ", 0x" << this << "]" << std::endl;
		return *this;
	}

	void whoAmI()
	{
		if(m_enableLogs)
			std::cout << " I am " << m_name << std::endl;

		m_dummyName = m_name; // Dummy operation to prevent optimization
	}
};
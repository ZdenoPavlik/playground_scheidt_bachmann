#include <string>
#include <iostream>

class PersonSalaryCalculator final
{
public:
	PersonSalaryCalculator(const std::string name, const int salary)
		: m_name(name)
		, m_salary(salary)
	{
	}

	void setChildrenCount(int childrenCount)
	{
		m_childrenCount = childrenCount;
	}

	std::string getName() const
	{
		return m_name;
	}

	[[nodiscard]] int calculateFinalSalary() const
	{
		int finalSalary = (m_salary * (100 - m_tax)) / 100;
		if(m_childrenCount)
		{
			finalSalary = finalSalary * (100 + (m_childrenCount * 10)) / 100; // 10% discount for each children
		}

		return finalSalary;
	}

	virtual ~PersonSalaryCalculator() = default;

private:
	std::string m_name;
	int m_salary{};		   // salary
	int m_tax{25};		   // 25%
	int m_childrenCount{}; // For salary discount
};

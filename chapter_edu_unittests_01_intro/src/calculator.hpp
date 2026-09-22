#pragma once

class Calculator
{
public:
	int add(const int a, const int b)
	{
		return (a + b);
	}

	int sub(const int a, const int b)
	{
		return (a - b);
	}

	int mul(const int a, const int b)
	{
		return (a * b);
	}

	int div(const int a, const int b)
	{
		return (a / b);
	}
};

/*Example complicated class
class MonthNameConverter
{
													// What happens if I entry 0.sp. 13
	std::string toString(const uint8_t number)		//Returns "May", "may", or "MAY"?
	{
	}

	uint8_t toNumber(std::string)					//Accepts all variant? "Sep", "September", "SEPTEMBER", ... ?
	{
	}
};
*/
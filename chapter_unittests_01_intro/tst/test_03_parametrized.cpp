#include <gtest/gtest.h>
#include <memory>

#include "calculator.hpp"

class CalculatorTest_03 : public ::testing::TestWithParam<int>
{
public:
	// You can add helper objects or setup logic here if needed, i.e. Setup and Teardown
	Calculator calc;
};

TEST_P(CalculatorTest_03, addition_positive)
{
	int number = GetParam(); // Retrieve the current parameter value
	std::cout << "Testing sum of " << number << " and " << number << std::endl;
	EXPECT_EQ(calc.add(number, number), number + number);
}

INSTANTIATE_TEST_SUITE_P(Addition,												// Prefix name for this instantiation
	CalculatorTest_03,															// Test fixture class name
	::testing::Values(2, 4, 6, 8, 2.3, 10, 11, 12, (double)(2.4), (uint8_t)(1)) // List of parameters to test. Supports heterogenous values!

);
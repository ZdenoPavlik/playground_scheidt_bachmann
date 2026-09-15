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
	EXPECT_EQ(calc.add(number, number), 4);
}

INSTANTIATE_TEST_SUITE_P(CalculatorTest_03, // Prefix name for this instantiation
	Addition,								// Test fixture class name
	::testing::Values(2, 4, 6, 8)			// List of parameters to test
);
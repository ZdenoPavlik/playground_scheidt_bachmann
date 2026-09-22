#include <gtest/gtest.h>

#include "calculator.hpp"

TEST(CalculatorTest, addition_positive)
{
	Calculator calc;
	EXPECT_EQ(calc.add(2, 3), 5);
	EXPECT_EQ(calc.add(1, 1), 2);
}

TEST(CalculatorTest, addition_negative)
{
	Calculator calc;
	ASSERT_NE(calc.add(1, 1), 5);
	EXPECT_NE(calc.add(1, 1), 5);
}

TEST(CalculatorTest, substraction_positive)
{
	Calculator calc;
	EXPECT_EQ(calc.sub(4, 3), 1);
	EXPECT_EQ(calc.sub(1, 1), 0);
}

TEST(CalculatorTest, substraction_negative)
{
	Calculator calc;
	ASSERT_NE(calc.sub(1, 1), 5);
	EXPECT_NE(calc.sub(1, 1), 5);
}

TEST(CalculatorTest, multiply_positive)
{
	Calculator calc;
	EXPECT_EQ(calc.mul(2, 3), 6);
	EXPECT_EQ(calc.mul(1, 3), 3);
}

TEST(CalculatorTest, multiply_negative)
{
	Calculator calc;
	ASSERT_NE(calc.mul(1, 1), 5);
	EXPECT_NE(calc.mul(1, 1), 5);
}

TEST(CalculatorTest, divide_positive)
{
	Calculator calc;
	EXPECT_EQ(calc.div(4, 2), 2);
	EXPECT_EQ(calc.div(1, 1), 1);
}

TEST(CalculatorTest, divide_negative)
{
	Calculator calc;
	ASSERT_NE(calc.div(1, 1), 5);
	EXPECT_NE(calc.div(1, 1), 5);
}

#include <gtest/gtest.h>
#include <memory>

#include "calculator.hpp"

class CalculatorTest_02 : public testing::Test
{
protected:
	void SetUp() override
	{
		calc = std::make_unique<Calculator>();
	}

	void TearDown() override
	{
		calc.reset();
	}

	std::unique_ptr<Calculator> calc;
};

TEST_F(CalculatorTest_02, addition_positive)
{
	EXPECT_EQ(calc->add(2, 3), 5);
	EXPECT_EQ(calc->add(1, 1), 2);
}

TEST_F(CalculatorTest_02, addition_negative)
{
	ASSERT_NE(calc->add(1, 1), 5);
	EXPECT_NE(calc->add(1, 1), 5);
}

TEST_F(CalculatorTest_02, substraction_positive)
{
	EXPECT_EQ(calc->sub(4, 3), 1);
	EXPECT_EQ(calc->sub(1, 1), 0);
}

TEST_F(CalculatorTest_02, substraction_negative)
{
	ASSERT_NE(calc->sub(1, 1), 5);
	EXPECT_NE(calc->sub(1, 1), 5);
}

TEST_F(CalculatorTest_02, multiply_positive)
{
	EXPECT_EQ(calc->mul(2, 3), 6);
	EXPECT_EQ(calc->mul(1, 3), 3);
}

TEST_F(CalculatorTest_02, multiply_negative)
{
	ASSERT_NE(calc->mul(1, 1), 5);
	EXPECT_NE(calc->mul(1, 1), 5);
}

TEST_F(CalculatorTest_02, divide_positive)
{
	EXPECT_EQ(calc->div(4, 2), 2);
	EXPECT_EQ(calc->div(1, 1), 1);
}

TEST_F(CalculatorTest_02, divide_negative)
{
	ASSERT_NE(calc->div(1, 1), 5);
	EXPECT_NE(calc->div(1, 1), 5);
}

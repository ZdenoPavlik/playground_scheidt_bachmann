#include <gtest/gtest.h>

#include "calculator.hpp"

void segfault()
{
	std::cerr << "Memory access violation" << std::endl;

	int* pointer = nullptr;
	*pointer = 5;
}

TEST(CalculatorTest, Additional)
{
	Calculator calc;
	EXPECT_EQ(calc.add(2, 3), 5);

	EXPECT_TRUE(calc.add(2, 3) > 1);
	ASSERT_TRUE(calc.add(2, 3) > 1);

	EXPECT_GT(calc.add(2, 3), 1); // Greater than
	EXPECT_LT(calc.add(2, 3), 6); // Less than

	EXPECT_STREQ("One", "One");
	EXPECT_STRCASEEQ("One", "ONE");

	EXPECT_ANY_THROW({ throw std::exception(); });
	EXPECT_DEATH(segfault(), "Memory access violation");
}

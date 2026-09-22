#include <gtest/gtest.h>

#include "PersonSalaryCalculator.hpp"

TEST(PersonSalaryCalculatorTest, simpleCreation)
{
	PersonSalaryCalculator person("Bob", 2000);

	EXPECT_EQ(person.getName(), "Bob"); // Case sensitive, simple to use
	EXPECT_STRNE(person.getName().c_str(), "");
	EXPECT_STRCASEEQ(person.getName().c_str(), "Bob");
}

TEST(PersonSalaryCalculatorTest, simpleSalary)
{
	PersonSalaryCalculator person1("Bob", 1000);
	EXPECT_EQ(person1.calculateFinalSalary(), 750);

	PersonSalaryCalculator person2("Bob", 2000);
	EXPECT_EQ(person2.calculateFinalSalary(), 1500);

	PersonSalaryCalculator person3("Bob", 3000);
	EXPECT_EQ(person3.calculateFinalSalary(), 2250);
}

TEST(PersonSalaryCalculatorTest, childrenDiscount)
{
	PersonSalaryCalculator person("Bob", 1000);
	EXPECT_EQ(person.calculateFinalSalary(), 750);

	person.setChildrenCount(1);
	EXPECT_EQ(person.calculateFinalSalary(), 825);

	person.setChildrenCount(2);
	EXPECT_EQ(person.calculateFinalSalary(), 900);

	person.setChildrenCount(3);
	EXPECT_EQ(person.calculateFinalSalary(), 975);
}

/*
TEST(PersonSalaryCalculatorTest, negativeChildren)
{
	PersonSalaryCalculator person("Bob", 1000);
	EXPECT_EQ(person.calculateFinalSalary(), 750);

	person.setChildrenCount(-1);
	EXPECT_EQ(person.calculateFinalSalary(), 825);
}*/

/*TEST(PersonSalaryCalculatorTest, emptyName)
{
	PersonSalaryCalculator person("", 1000);
	EXPECT_NE(person.getName(), "");
}*/

/*TEST(PersonSalaryCalculatorTest, emptySalary)
{
	PersonSalaryCalculator person("Bob", 0);
	EXPECT_GT(person.calculateFinalSalary(), 0);
}*/

/*TEST(PersonSalaryCalculatorTest, negativeSalary)
{
	PersonSalaryCalculator person("Bob", -1000);
	EXPECT_GT(person.calculateFinalSalary(), 0);
}*/
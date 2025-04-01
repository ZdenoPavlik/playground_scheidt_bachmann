#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FooTest, AddsNumbersCorrectly) {
    EXPECT_EQ((2 + 3), 5);
}
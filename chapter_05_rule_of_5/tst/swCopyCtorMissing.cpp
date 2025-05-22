
#include "inc/swCopyCtorMissing.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../tools/memoryAnalyzer.hpp"

TEST(SwCopyCtorMissing, test1) {
    // This causes no memory leak, because "new" and "delete" are properly called

    size_t memoryBeforeAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};
    SwCopyCtorMissing var{"Bla"};
    size_t memoryAfterAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};

    EXPECT_TRUE(MemoryAnalyzer::isMemoryLeakInTolerance(memoryBeforeAllocation, memoryAfterAllocation, 20));
}

TEST(SwCopyCtorMissing, test2) {
    // This causes double free exception, because even though new and delete are called, proper handling of copy ctor is missing and only
    // pointer address is copied. Content is not duplicated

    size_t memoryBeforeAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};
    SwCopyCtorMissing var{"Bla"};
    size_t memoryAfterAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};

    EXPECT_TRUE(MemoryAnalyzer::isMemoryLeakInTolerance(memoryBeforeAllocation, memoryAfterAllocation, 20));
}

void someFunc(SwCopyCtorMissing inst) {
    sizeof(inst);
}

TEST(SwCopyCtorMissing, test3) {
    EXPECT_DEATH(
        {
            // This causes double free exception, because even though new and delete are called, proper handling of copy ctor is missing and
            // only pointer address is copied. Content is not duplicated
            SwCopyCtorMissing var{"Bla"};
            someFunc(var);  // creates copy
        },
        "double free()");  // sets regex to match error message
}
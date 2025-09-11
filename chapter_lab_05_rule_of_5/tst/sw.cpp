
#include "inc/sw.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../tools/memoryAnalyzer.hpp"

TEST(Sw, test1) {
    // This causes memory leak, because "new" is called in constructor, but "delete" is called

    size_t memoryBeforeAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};
    Sw var{"Bla"};

    size_t memoryAfterAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};

    EXPECT_TRUE(MemoryAnalyzer::isMemoryLeakInTolerance(memoryBeforeAllocation, memoryAfterAllocation));
}
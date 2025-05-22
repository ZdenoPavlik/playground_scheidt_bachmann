
#include "inc/swCopyCtorProper.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../tools/memoryAnalyzer.hpp"

TEST(SwCopyCtorProper, test1) {
    const size_t memoryBeforeAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};

    SwCopyCtorProper var1{"bla"};
    SwCopyCtorProper var2{"bla2"};

    var1 = var2;  // "Calling copy assignment"

    const size_t memoryAfterAllocation{MemoryAnalyzer::getCurrentMemoryUsage()};

    EXPECT_TRUE(MemoryAnalyzer::isMemoryLeakInTolerance(memoryBeforeAllocation, memoryAfterAllocation));
}
#include <iostream>

#include "../tools/memoryAnalyzer.hpp"

void memoryLeakExample() {
    const size_t memInitialUsage{MemoryAnalyzer::getCurrentMemoryUsage()};
    std::cout << "Memory usage: " << memInitialUsage << " KB" << std::endl;

    int* arr = new int[1000000];     // Allocate memory dynamically
    std::memset(arr, '2', 1000000);  // Touch the memory to ensure it's actually used

    std::cout << "After allocation: " << MemoryAnalyzer::getCurrentMemoryUsage() << " KB" << std::endl;

    delete[] arr;    // Free allocated memory
    //malloc_trim(0);  // Force memory to be returned to the OS

    const size_t memAfterDeallocation{MemoryAnalyzer::getCurrentMemoryUsage()};
    std::cout << "After deallocation: " << memAfterDeallocation << " KB" << std::endl;

    if (MemoryAnalyzer::isMemoryLeakInTolerance(memInitialUsage, memAfterDeallocation)) {
        std::cout << "Memory usage is in tolerance" << std::endl;
    } else {
        std::cerr << "Memory usage out of tolerance!" << std::endl;
    }
}

int main() {
    std::cout << "Hello World!" << std::endl;

    memoryLeakExample();

    return 0;
}

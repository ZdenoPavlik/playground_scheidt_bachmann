#include <malloc.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class MemoryAnalyzer {
   public:
    static bool isMemoryLeakInTolerance(const size_t memoryBefore, const size_t memoryAfter, const uint tolerance = 1024) {
        bool result = (memoryAfter - memoryBefore) < tolerance ? true : false;

        return result;
    }

    static size_t getCurrentMemoryUsage() {
        std::ifstream statusFile("/proc/self/status");
        std::string line;
        size_t memoryUsage = 0;

        if (!statusFile) {
            std::cerr << "Error: Unable to open /proc/self/status" << std::endl;
            return 0;
        }

        while (std::getline(statusFile, line)) {
            if (line.find("VmRSS:") == 0) {  // Look for VmRSS line
                std::istringstream iss(line);
                std::string key, unit;
                iss >> key >> memoryUsage >> unit;  // Extract value
                break;
            }
        }

        return memoryUsage;  // Memory in KB
    }
};
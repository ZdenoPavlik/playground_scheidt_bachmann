#include <malloc.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

class MemoryAnalyzer {
   public:
    static bool isMemoryLeakInTolerance(const size_t memoryBefore, const size_t memoryAfter, const unsigned int tolerance = 1024) {
        bool result = (memoryAfter - memoryBefore) < tolerance ? true : false;

        return result;
    }

    static size_t getCurrentMemoryUsage() {
    #ifdef _WIN32
        PROCESS_MEMORY_COUNTERS info;
        GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
        return info.WorkingSetSize / 1024;
    #else
        // Linux version
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
    #endif
    }
};
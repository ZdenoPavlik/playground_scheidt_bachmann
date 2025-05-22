#include <cstring>
#include <iostream>
#include <string>

class SwCopyCtorMissing {
   public:
    explicit SwCopyCtorMissing(std::string newString) : data(new char[newString.size() + 1]) {
        strcpy(data, newString.data());
    }

    ~SwCopyCtorMissing() {
        delete[] data;
        data = nullptr;
    }

   private:
    char* data{};  //"delete" called, but on copy ctor only pointer address is copied, not content
};
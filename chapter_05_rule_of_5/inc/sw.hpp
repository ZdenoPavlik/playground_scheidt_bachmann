#include <cstring>
#include <iostream>
#include <string>

class Sw {
   public:
    explicit Sw(std::string newString) : data(new char[newString.size() + 1]) {
        strcpy_s(data, newString.size()+1, newString.data());
    }

   private:
    char* data{};  // No "delete" called
};
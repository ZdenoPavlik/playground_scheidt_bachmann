#include <cstring>
#include <iostream>
#include <string>

class SwFull {
   public:
    explicit SwFull(std::string newString) : data(new char[newString.size() + 1]) {
        strcpy_s(data, newString.size()+1, newString.data());
    }

    ~SwFull() {
        delete[] data;
        data = nullptr;
    }

    SwFull(const SwFull& other) {
        std::cout << "Calling copy constructor" << std::endl;
        delete[] data;
        data = new char[sizeof(other.data)];
        strcpy_s(data, sizeof(other.data), other.data);
    }

    SwFull& operator=(const SwFull& other) {
        std::cout << "Calling copy assignment" << std::endl;

        data = other.data;
        const_cast<SwFull*>(&other)->data = nullptr;  // cast away "const", ugly solution

        return *this;
    }

    SwFull([[maybe_unused]] SwFull&& other) noexcept {
        std::cout << "Calling move constructor" << std::endl;
    }

    SwFull& operator=([[maybe_unused]] SwFull&& other) noexcept {
        std::cout << "Calling move assignment" << std::endl;
        return *this;
    }

    const char* getData() const {
        return data;
    }

   private:
    char* data{};
};
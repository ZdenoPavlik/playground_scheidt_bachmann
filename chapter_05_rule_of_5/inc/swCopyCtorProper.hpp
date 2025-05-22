#include <cstring>
#include <iostream>
#include <string>

class SwCopyCtorProper {
   public:
    explicit SwCopyCtorProper(std::string newString) : data(new char[newString.size() + 1]) {
        strcpy(data, newString.data());
    }

    ~SwCopyCtorProper() {
        delete[] data;
        data = nullptr;
    }

    SwCopyCtorProper(const SwCopyCtorProper& other) {
        std::cout << "Calling copy constructor" << std::endl;
        delete[] data;
        data = new char[sizeof(other.data)];
        strcpy(data, other.data);
    }

    SwCopyCtorProper& operator=(SwCopyCtorProper& other) {
        std::cout << "Calling copy assignment" << std::endl;

        data = other.data;
        other.data = nullptr;

        return *this;
    }

    const char* getData() const {
        return data;
    }

   private:
    char* data{};
};
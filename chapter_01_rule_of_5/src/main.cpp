#include <iostream>

#include "../tools/memoryAnalyzer.hpp"
#include "inc/swFull.hpp"

/*
Copy Constructor - When is it called?
    When an object is initialized from another object of the same type.
    When an object is passed by value to a function.
    When an object is returned by value from a function.
Move Constructor - When is it called?
    When an rvalue (temporary object) is used to initialize another object.
    When an object is returned by value but can be moved instead of copied.
Copy Assignment Operator (operator=(const A&)) - When is it called?
    When an already existing object is assigned a new value from another object.
Move Assignment Operator (operator=(A&&)) -When is it called?
    When an rvalue (temporary object) is assigned to an existing object.


Constructor/Operator	            When is it Called?
Default Constructor	                When an object is created with no arguments.
Copy Constructor	                When an object is initialized from another object.
Move Constructor	                When an object is initialized using an rvalue.
Copy Assignment (operator=)(A&)	    When an object is assigned a value from another object.
Move Assignment (operator=)(A&&)    When an rvalue is assigned to an object.

https://howardhinnant.github.io/smf.jpg
*/

void makeACopy([[maybe_unused]] SwFull var) {
    var.getData();
}

SwFull create() {
    return SwFull("bla");
}

int main() {
    SwFull var1{"var1"};
    SwFull var2{"var2"};
    SwFull var3{"bla3"};

    var1 = var2;  // "Calling copy assignment"
    std::cout << "var1 class contains [" << var1.getData() << "]" << std::endl;

    makeACopy(var3);    // "Calling copy constructor"
    SwFull var4{var1};  // "Calling copy constructor"

    SwFull var5 = std::move(var4);  // "Calling move constructor"
    SwFull var6 = create();         // "Calling move constructor"

    SwFull var7{"bla7"};
    var7 = create();  //"Calling move assignment"

    return 0;
}

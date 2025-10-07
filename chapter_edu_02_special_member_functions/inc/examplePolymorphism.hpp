#include <iostream>
#include <vector>
#include <memory>

class Animal
{
public:
    virtual void speak() const = 0; // Enforces every child to implement this function
    virtual ~Animal() = default;    // Virtual destructor for proper cleanup of derived classes
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Meow!" << std::endl;
    }
};

class Raven : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Kra kra!" << std::endl;
    }
};

void makeNoise(const Animal& animal)
{
    animal.speak();
}

void examplePolymorphism()
{
    {
        Dog dog;
        makeNoise(dog);
    }

    {
        std::vector<std::unique_ptr<Animal>> zoo;

        zoo.emplace_back(std::make_unique<Dog>());
        zoo.emplace_back(std::make_unique<Cat>());
        zoo.emplace_back(std::make_unique<Raven>());

        for(const auto& animal : zoo)
        {
            animal->speak();
        }
    }
}
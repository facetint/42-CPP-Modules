#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default constructor called " << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Constructor called " << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Copy constructor called " << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor called " << std::endl;
}


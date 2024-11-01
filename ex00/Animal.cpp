#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default constructor called - (Animal)" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Constructor called - (Animal)" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Animal)" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor called - (Animal)" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Assignation operator called - (Animal)" << std::endl;
    return *this;
}

void Animal::setType(const std::string type)
{
    this->_type = type;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor called - (Animal)" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Parameterized constructor called - (Animal)" << std::endl;
}

Dog::Dog(const Dog& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Animal)" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called - (Animal)" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
    }
    std::cout << "Assignation operator called - (Animal)" << std::endl;
    return *this;
}

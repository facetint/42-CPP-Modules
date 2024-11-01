#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
    std::cout << "Default constructor called - (Dog)" << std::endl;
}

Dog::Dog(const Dog& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Dog)" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called - (Dog)" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
    }
    std::cout << "Assignation operator called - (Dog)" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;   
}


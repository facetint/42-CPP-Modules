#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor called " << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    *this = other;
    std::cout << "Copy constructor called " << std::endl;
}
Cat::~Cat()
{
    std::cout << "Destructor called " << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
    }
    std::cout << "Assignation operator called " << std::endl;
    return *this;
}

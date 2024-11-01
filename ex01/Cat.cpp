#include "Cat.hpp"

Cat::Cat()
{
    setType("Cat");
    std::cout << "Default constructor called - (Cat)" << std::endl;
}

Cat::Cat(const Cat& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Cat)" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Destructor called - (Cat)" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
    }
    std::cout << "Assignation operator called - (Cat)" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

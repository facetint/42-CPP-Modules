#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    setType("WrongCat");
    std::cout << "Default constructor called - (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    *this = other;
    std::cout << "Copy constructor called - (WrongCat)" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called - (WrongCat)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        this->setType(other.getType());
    }
    std::cout << "Assignation operator called - (WrongCat)" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}

void WrongCat::display() const
{
    std::cout << "---------------------------" << std::endl;
    std::cout << WHITE_COLOR << "My type is: " << BLUE_COLOR << getType() << RESET << std::endl;
    makeSound();
    std::cout << "---------------------------" << std::endl;
}
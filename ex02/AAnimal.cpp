#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "Default constructor called - (AAnimal)" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    *this = other;
    std::cout << "Copy constructor called - (AAnimal)" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor called - (AAnimal)" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "Assignation operator called - (AAnimal)" << std::endl;
    return *this;
}

void AAnimal::setType(const std::string type)
{
    this->_type = type;
}

std::string AAnimal::getType(void) const
{
    return this->_type;
}

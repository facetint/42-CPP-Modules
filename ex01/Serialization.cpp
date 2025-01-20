#include "Serialization.hpp"

Serialization::Serialization()
{
    std::cout << "Default constructor called" << std::endl;
}

Serialization::Serialization(Serialization const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Serialization::~Serialization()
{
    std::cout << "Destructor called" << std::endl;
}

Serialization & Serialization::operator=(Serialization const & other)
{
    std::cout << "Assignation operator called" << std::endl;
    (void)other;
    return *this;
}


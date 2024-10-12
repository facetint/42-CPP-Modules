#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int number) : value(number)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return (*this);
}

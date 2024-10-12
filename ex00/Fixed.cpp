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

void Fixed::setValue(const int& number)
{
    std::cout << "setValue member function called" << std::endl;
    this->value = number;
}

int Fixed::getValue(void) const
{
    std::cout << "getValue member function called" << std::endl;
    return this->value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setValue(other.getValue());
    return (*this);
}

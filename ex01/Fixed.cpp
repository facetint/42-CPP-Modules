#include "Fixed.hpp"

Fixed::Fixed(void){
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = number << this->bitCount;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(number * (1 << this->bitCount));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return (this->value >> this->bitCount);
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << this->bitCount));
}

int Fixed::getRawBit(void) const
{
    std::cout << "getRawBit member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBit(const int raw)
{
    std::cout << "setRawBit member function called" << std::endl;
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->setRawBit(other.getRawBit());
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

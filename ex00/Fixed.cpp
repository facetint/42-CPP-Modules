#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::Fixed(int number) : value(number)
{

}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setValue(const int& number)
{
    this->value = number;
}

int Fixed::getValue(void) const
{
    return this->value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    this->setValue(other.getValue());
    return (*this);
}

#include "Fixed.hpp"

Fixed::Fixed()
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

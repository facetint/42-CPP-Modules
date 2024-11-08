#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int number)
{
	this->value = number << this->bitCount;
}
Fixed::Fixed(const float number){
	this->value = roundf(number * (1 << this->bitCount));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const{

	return ((float)this->value / (1 << this->bitCount));
}

int		Fixed::toInt(void) const{

	return (this->value >> this->bitCount);
}

int		Fixed::getRawBit(void) const{

	return (this->value);
}

void	Fixed::setRawBit(const int raw){

	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.getRawBit();
	}
	return (*this);
}

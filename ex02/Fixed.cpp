#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	value = 8;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed& other) const{
	return this->value > other.value ? true : false;
}

bool Fixed::operator<(const Fixed& other) const{
	return this->value < other.value ? true : false;
}

bool Fixed::operator>=(const Fixed& other) const{
	return this->value >= other.value ? true : false;
}

bool Fixed::operator<=(const Fixed& other) const{
	return this->value <=  other.value ? true : false;
}

bool Fixed::operator==(const Fixed& other) const{
	return this->value == other.value ? true : false;
}

bool Fixed::operator!=(const Fixed& other) const{
	return this->value != other.value ? true : false;
}

Fixed Fixed::operator+(const Fixed& other) const{
	return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed& other) const{
	return this->toFloat() - other.toFloat();
} 

Fixed Fixed::operator*(const Fixed& other) const{
	return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed& other) const{
	return this->toFloat() / other.toFloat();
}

Fixed& Fixed::operator+=(const Fixed& other){
	*this = *this + other;
	return (*this);
}

Fixed& Fixed::operator-=(const Fixed& other){
	*this = *this - other;
	return (*this);
}

Fixed& Fixed::operator*=(const Fixed& other){
	*this = *this * other;
	return (*this);
}

Fixed& Fixed::operator/=(const Fixed& other){
	*this = *this / other;
	return (*this);
}

Fixed& Fixed::operator++(void){
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void){
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return a > b ? a : b;
}

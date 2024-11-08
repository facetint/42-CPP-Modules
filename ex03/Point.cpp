#include "Point.hpp"

Point::Point() : x(0), y(0){
    std::cout << "Default consturctor called" << std::endl;
}

Point::~Point(){
    std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y){
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y){
    std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y){
    std::cout << "Parameterized constructor called" << std::endl;
}

const Fixed& Point::getX(void) const{
    return this->x;
}

const Fixed& Point::getY(void) const{
    return this->y;
}

Point& Point::operator=(const Point& other){
    const_cast<Fixed&>(x) = other.getX();
    const_cast<Fixed&>(y) = other.getY();

    return (*this);
}

#ifndef POINT_HPP

# define POINT_HPP

# include <iostream>
#include "Fixed.hpp"

class Point{

private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    ~Point();
    Point(const Point& other);
    Point(const float x, const float y);
    Point& operator=(const Point& other);
    Point(const Fixed x, const Fixed y);
    const Fixed& getX(void) const;
    const Fixed& getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif
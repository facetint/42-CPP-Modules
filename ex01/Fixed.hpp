#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int value;
    static const int bitCount = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(int number);
    Fixed(const float number);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int bitCount = 8;

public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed(const int number);
    Fixed(const float number);
    ~Fixed();
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBit(void) const;
    void setRawBit(const int raw);
    Fixed& operator=(const Fixed& other);
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

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
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed& operator+=(const Fixed& other);
    Fixed& operator-=(const Fixed& other);
    Fixed& operator*=(const Fixed& other);
    Fixed& operator/=(const Fixed& other);
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

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
	~Fixed();

	int getValue() const;
	void setValue(const int& number);

	Fixed& operator=(const Fixed& other);

};

#endif
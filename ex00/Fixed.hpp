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

	int  getRawBits(void) const;
	void  setRawBits(int const raw);

	Fixed& operator=(const Fixed& other);

};

#endif
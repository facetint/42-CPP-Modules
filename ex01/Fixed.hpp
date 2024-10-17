/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:25:26 by facetint          #+#    #+#             */
/*   Updated: 2024/10/17 13:25:27 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
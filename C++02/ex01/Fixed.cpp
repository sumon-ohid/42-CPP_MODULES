/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:09:19 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 11:10:20 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    _fixedPointValue = fixed._fixedPointValue;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

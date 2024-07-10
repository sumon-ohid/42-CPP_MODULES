/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:09:19 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 15:25:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Fixed::Fixed()
{
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
    return (_fixedPointValue);
}

void Fixed::setRawBits(const int raw)
{
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)_fixedPointValue / (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    this->_fixedPointValue = fixed.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

// < > <= >= == !=
bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed)const
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->getRawBits() != fixed.getRawBits());
}

//a++
Fixed Fixed::operator++(int)
{
    Fixed instance = *this;
    
    this->_fixedPointValue++;
    return (instance);
}

//++a
Fixed Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}

//a--
Fixed Fixed::operator--(int)
{
    Fixed instance = *this;
    
    this->_fixedPointValue--;
    return (instance);
}

//--a
Fixed Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}
// - + * /
Fixed Fixed::operator-(const Fixed &fixed)
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator+(const Fixed &fixed)
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed)
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed)
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
    return (x > y ? x : y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
    return (x > y ? x : y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
    return (x < y ? x : y);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
    return (x < y ? x : y);
}
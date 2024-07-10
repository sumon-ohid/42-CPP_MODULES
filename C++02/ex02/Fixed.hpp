/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:09:03 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 15:10:10 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int					_fixedPointValue;
        static const int	_fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();
        
        Fixed &operator=(const Fixed &fixed);
        
        int	getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);
        //a++
        Fixed operator++(int);
        //++a
        Fixed operator++(void);
        //a--
        Fixed operator--(int);
        //--a
        Fixed operator--(void);

        static const Fixed &min(const Fixed &x, const Fixed &y);
        static Fixed &min( Fixed &x, Fixed &y);
        static const Fixed &max(const Fixed &x, const Fixed &y);
        static Fixed &max(Fixed &x, Fixed &y);
};

std::ostream &operator<<(std::ostream& os, const Fixed& fixed);

#endif
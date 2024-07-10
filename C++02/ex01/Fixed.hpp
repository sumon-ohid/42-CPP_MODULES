/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:09:03 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 11:07:37 by msumon           ###   ########.fr       */
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
        Fixed &operator=(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:25:10 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 16:04:31 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &point);
        ~Point();
        
        Point &operator=(const Point &point);
        
        float getX() const;
        float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
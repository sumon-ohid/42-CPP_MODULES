/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:28:46 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 15:59:23 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

// Default constructor
Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

// Copy constructor
Point::Point(const Point &point) : _x(point.getX()), _y(point.getY())
{
}

// Destructor
Point::~Point()
{
}

// Assignment operator
Point &Point::operator=(const Point &point)
{
    return (*this);
}

float Point::getX() const
{
    return _x.toFloat();
}

float Point::getY() const
{
    return _y.toFloat();
}
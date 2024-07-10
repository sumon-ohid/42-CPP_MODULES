/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:08:48 by msumon            #+#    #+#             */
/*   Updated: 2024/07/10 16:05:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(0.0f, 0.0f); // Triangle vertex A
    Point b(0.0f, 1.0f); // Triangle vertex B
    Point c(1.0f, 0.0f); // Triangle vertex C

    Point insidePoint(0.1f, 0.1f); // Point inside the triangle
    Point outsidePoint(-0.1f, 0.1f); // Point outside the triangle
    Point edgePoint(0.5f, 0.5f); // Point on the edge of the triangle
    Point vertexPoint = a; // Point at a vertex of the triangle

    std::cout << "Point inside triangle: " << (bsp(a, b, c, insidePoint) ? "True" : "False") << std::endl;
    std::cout << "Point outside triangle: " << (bsp(a, b, c, outsidePoint) ? "True" : "False") << std::endl;
    std::cout << "Point on edge of triangle: " << (bsp(a, b, c, edgePoint) ? "True" : "False") << std::endl;
    std::cout << "Point at vertex of triangle: " << (bsp(a, b, c, vertexPoint) ? "True" : "False") << std::endl;

    return 0;
}

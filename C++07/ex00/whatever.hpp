/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:32:52 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 12:28:27 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
    T temp;
    
    temp = x;
    x = y;
    y = temp;
}

template <typename T>
T min(T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template <typename T>
T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

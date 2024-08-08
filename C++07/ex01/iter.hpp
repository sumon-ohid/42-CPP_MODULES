/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:14:02 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 12:28:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T const &))
{
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void print_T(T const &x)
{
    std::cout << x << std::endl;
}

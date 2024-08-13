/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:15:31 by msumon            #+#    #+#             */
/*   Updated: 2024/08/13 09:43:31 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>

template <typename T>
int easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error(" Not found");
    return *it;
}
 
template <typename T>
void testEasyfind(T &container, int n)
{
    try
    {
        std::cout << easyfind(container, n) << " found";
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << n << e.what() << std::endl;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:05:09 by msumon            #+#    #+#             */
/*   Updated: 2024/08/16 13:26:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <iterator>

// Function template to merge two sorted halves
template <typename T>
void merge(T& _array, typename T::iterator left, typename T::iterator mid, typename T::iterator right)
{
    T _leftArray(left, mid);
    T _rightArray(mid, right);

    (void)_array;
    typename T::iterator i = _leftArray.begin();
    typename T::iterator j = _rightArray.begin();
    typename T::iterator k = left;

    while (i != _leftArray.end() && j != _rightArray.end())
    {
        if (*i <= *j)
            *k++ = *i++;
        else
            *k++ = *j++;
    }
    while (i != _leftArray.end())
        *k++ = *i++;

    while (j != _rightArray.end())
        *k++ = *j++;
}

// Ford-Johnson sorting algorithm
template <typename T>
void fordJohnsonSort(T& _array, typename T::iterator left, typename T::iterator right)
{
    if (std::distance(left, right) > 1)
    {
        typename T::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        // Recursively sort the first and second halves
        fordJohnsonSort(_array, left, mid);
        fordJohnsonSort(_array, mid, right);

        // Merge the sorted halves
        merge(_array, left, mid, right);
    }
}

// Helper function to call fordJohnsonSort with list
template <typename T>
void fordJohnsonSort(T& _array)
{
    if (!_array.empty())
        fordJohnsonSort(_array, _array.begin(), _array.end());
}

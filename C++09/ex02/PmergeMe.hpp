/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:05:09 by msumon            #+#    #+#             */
/*   Updated: 2024/08/16 12:47:27 by msumon           ###   ########.fr       */
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
void merge(T& arr, typename T::iterator left, typename T::iterator mid, typename T::iterator right)
{
    T leftArr(left, mid);
    T rightArr(mid, right);

    (void)arr;
    typename T::iterator i = leftArr.begin();
    typename T::iterator j = rightArr.begin();
    typename T::iterator k = left;

    while (i != leftArr.end() && j != rightArr.end())
    {
        if (*i <= *j)
            *k++ = *i++;
        else
            *k++ = *j++;
    }
    while (i != leftArr.end())
        *k++ = *i++;

    while (j != rightArr.end())
        *k++ = *j++;
}

// Ford-Johnson sorting algorithm
template <typename T>
void fordJohnsonSort(T& arr, typename T::iterator left, typename T::iterator right)
{
    if (std::distance(left, right) > 1)
    {
        typename T::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        // Recursively sort the first and second halves
        fordJohnsonSort(arr, left, mid);
        fordJohnsonSort(arr, mid, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to call fordJohnsonSort with list
template <typename T>
void fordJohnsonSort(T& arr)
{
    if (!arr.empty())
        fordJohnsonSort(arr, arr.begin(), arr.end());
}

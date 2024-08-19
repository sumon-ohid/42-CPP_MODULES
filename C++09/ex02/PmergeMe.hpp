/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:05:09 by msumon            #+#    #+#             */
/*   Updated: 2024/08/19 17:59:39 by msumon           ###   ########.fr       */
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
#include <cstring>
#include <string>

extern int comparison_count;

template <typename Container>
void split_array_into_pair(const Container &array, Container &larger, Container &smaller)
{
    typename Container::const_iterator it = array.begin();
    while (it != array.end())
    {
        typename Container::const_iterator next_it = it;
        ++next_it;
        if (next_it != array.end())
        {
            comparison_count++;
            if (*it > *next_it)
            {
                larger.push_back(*it);
                smaller.push_back(*next_it);
            }
            else
            {
                larger.push_back(*next_it);
                smaller.push_back(*it);
            }
            ++it;
        }
        else
        {
            larger.push_back(*it);
        }
        ++it;
    }
}

template <typename Container>
void insert_with_binary_search(Container &sorted, typename Container::value_type value)
{
    typename Container::iterator left = sorted.begin();
    typename Container::iterator right = sorted.end();

    while (left != right)
    {
        typename Container::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        comparison_count++;
        if (*mid < value)
        {
            left = mid;
            ++left;
        }
        else
        {
            right = mid;
        }
    }

    sorted.insert(left, value);
}

template <typename Container>
void merge(Container &left, Container &right, Container &result)
{
    typename Container::iterator it_left = left.begin();
    typename Container::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        comparison_count++;
        if (*it_left <= *it_right)
        {
            result.push_back(*it_left);
            ++it_left;
        }
        else
        {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end())
    {
        result.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end())
    {
        result.push_back(*it_right);
        ++it_right;
    }
}

template <typename Container>
void merge_sort(Container &container)
{
    if (container.size() <= 1)
        return;

    Container left, right;
    typename Container::iterator it = container.begin();
    std::advance(it, std::distance(container.begin(), container.end()) / 2);

    left.insert(left.begin(), container.begin(), it);
    right.insert(right.begin(), it, container.end());

    merge_sort(left);
    merge_sort(right);

    container.clear();
    merge(left, right, container);
}

template <typename Container>
void fordJohnsonSort(Container &array)
{
    if (array.size() <= 1)
        return;

    Container larger, smaller;
    split_array_into_pair(array, larger, smaller);

    merge_sort(larger);

    Container sorted;
    sorted.push_back(smaller.front());
    sorted.insert(sorted.end(), larger.begin(), larger.end());

    typename Container::iterator it = smaller.begin();
    ++it;
    for (; it != smaller.end(); ++it)
    {
        insert_with_binary_search(sorted, *it);
    }

    array = sorted;
}

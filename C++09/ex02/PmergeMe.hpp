/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:05:09 by msumon            #+#    #+#             */
/*   Updated: 2024/08/28 10:09:43 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <cstring>
#include <string>
#include <deque>
#include <iomanip>

static int comparision_count = 0;

template <typename Container>
void splitArray(const std::pair<Container, Container> &pair, Container &larger, Container &smaller)
{
    typename Container::const_iterator it1 = pair.first.begin();
    typename Container::const_iterator it2 = pair.second.begin();

    while (it1 != pair.first.end() && it2 != pair.second.end())
    {
        comparision_count++;
        if (*it1 > *it2)
        {
            larger.push_back(*it1);
            smaller.push_back(*it2);
        }
        else
        {
            larger.push_back(*it2);
            smaller.push_back(*it1);
        }
        ++it1;
        ++it2;
    }

    while (it1 != pair.first.end())
    {
        smaller.push_back(*it1);
        ++it1;
    }

    while (it2 != pair.second.end())
    {
        smaller.push_back(*it2);
        ++it2;
    }
}

template <typename Container>
std::vector<int> generateJacobsthalNumbers(Container limit)
{
    std::vector<int> jacobsthal_numbers;
    jacobsthal_numbers.push_back(1);
    jacobsthal_numbers.push_back(3);

    int n = 2;
    while (true)
    {
        int j_num = jacobsthal_numbers[n - 1] + 2 * jacobsthal_numbers[n - 2];
        if (j_num >= limit)
            break;
        jacobsthal_numbers.push_back(j_num);
        ++n;
    }
    
    // std::vector<int> filled_numbers;
    // if (jacobsthal_numbers.size() < 1)
    //     filled_numbers.push_back(1);
    // for (unsigned int i = 2; i < jacobsthal_numbers.size(); ++i)
    // {
    //     int temp = jacobsthal_numbers[i];
    //     while (temp > jacobsthal_numbers[i - 1] && temp < limit)
    //     {
    //         filled_numbers.push_back(temp--);
    //     }
    // }
    return jacobsthal_numbers;
}

template <typename ForwardIterator, typename T>
ForwardIterator customLowerBound(ForwardIterator first, ForwardIterator last, const T& value)
{
    ForwardIterator it;
    typename std::iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first, last);

    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step);
        comparision_count++;
        if (*it < value)
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

template <typename Container>
void insertWithBinarySearch(Container &sorted, Container &smaller, const std::pair<Container, Container> &pair)
{
    if (smaller.empty())
        return;

    typename Container::value_type value = smaller.front();
    typename Container::const_iterator it1 = pair.first.begin();
    typename Container::const_iterator it2 = pair.second.begin();
    typename Container::value_type limit = 0;

    while (it1 != pair.first.end() && it2 != pair.second.end())
    {
        if (value == *it1)
        {
            limit = *it2;
            break;
        }
        else if (value == *it2)
        {
            limit = *it1;
            break;
        }
        ++it1;
        ++it2;
    }

    typename Container::iterator limit_it = std::find(sorted.begin(), sorted.end(), limit);

    std::vector<int> jacobsthal_numbers = generateJacobsthalNumbers(std::distance(sorted.begin(), limit_it));

    typename Container::iterator pos = limit_it;
    for (int i = 0; i < (int) jacobsthal_numbers.size(); ++i)
    {
        int index = jacobsthal_numbers[i];
        if (index >= std::distance(sorted.begin(), limit_it) || sorted[index] > value)
        {
            pos = sorted.begin() + index;
            break;
        }
    }

    typename Container::iterator it = customLowerBound(sorted.begin(), pos, value);
    
    sorted.insert(it, value);
    smaller.erase(smaller.begin());
}

template <typename Container>
void mergeNum(Container &left, Container &right, Container &result)
{
    typename Container::iterator it_left = left.begin();
    typename Container::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        comparision_count++;
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
void mergeSort(Container &container)
{
    if (container.size() <= 1)
        return;

    Container left, right;
    typename Container::iterator it = container.begin();
    std::advance(it, std::distance(container.begin(), container.end()) / 2);

    left.insert(left.begin(), container.begin(), it);
    right.insert(right.begin(), it, container.end());

    mergeSort(left);
    mergeSort(right);

    container.clear();
    mergeNum(left, right, container);
}

template <typename Container>
void insertTheSmallest(Container &sorted, Container &smaller, Container &larger, const std::pair<Container, Container> &pair)
{
    if (larger.empty())
        return;

    typename Container::value_type front = larger.front();
    typename Container::const_iterator it1 = pair.first.begin();
    typename Container::const_iterator it2 = pair.second.begin();

    while (it1 != pair.first.end() && it2 != pair.second.end())
    {
        if (front == *it1)
        {
            sorted.insert(sorted.begin(), *it2);
            smaller.erase(std::remove(smaller.begin(), smaller.end(), *it2), smaller.end());
            break;
        }
        else if (front == *it2)
        {
            sorted.insert(sorted.begin(), *it1);
            smaller.erase(std::remove(smaller.begin(), smaller.end(), *it1), smaller.end());
            break;
        }
        ++it1;
        ++it2;
    }
}

template <typename Container>
void fordJohnsonSort(Container &array)
{
    if (array.size() <= 1)
        return;
        
    std::pair<Container, Container> pair;
    for (typename Container::iterator it = array.begin(); it != array.end(); ++it)
    {
        typename Container::iterator next_it = it;
        ++next_it;
        if (next_it != array.end())
        {
            pair.first.push_back(*it);
            pair.second.push_back(*next_it);
            ++it;
        }
        else
            pair.first.push_back(*it);
    }
    
    Container larger, smaller;
    
    splitArray(pair, larger, smaller);
    
    mergeSort(larger);

    Container sorted;
    sorted = larger;
    
    insertTheSmallest(sorted, smaller, larger, pair);
    if (smaller.size() == 1 && smaller.front() > *(--sorted.end()))
    {
        sorted.insert(sorted.end(), smaller.front());
        smaller.erase(smaller.begin());
    }

    while (!smaller.empty())
    {
        insertWithBinarySearch(sorted, smaller, pair);
    }
    
    array = sorted;
    std::cout << "Comparision count: " << comparision_count << std::endl;
    comparision_count = 0;
}

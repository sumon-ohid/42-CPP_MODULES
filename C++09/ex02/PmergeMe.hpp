/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:05:09 by msumon            #+#    #+#             */
/*   Updated: 2024/08/21 19:12:41 by msumon           ###   ########.fr       */
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

static int comparision_count = 0;

template <typename Container>
void split_array(const std::pair<Container, Container> &pair, Container &larger, Container &smaller)
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
std::vector<int> generate_jacobsthal_numbers(Container limit)
{
    std::vector<int> jacobsthal_numbers;
    jacobsthal_numbers.push_back(0);
    jacobsthal_numbers.push_back(1);

    int n = 2;
    while (true)
    {
        int j_num = jacobsthal_numbers[n - 1] + 2 * jacobsthal_numbers[n - 2];
        if (j_num >= limit)
            break;
        jacobsthal_numbers.push_back(j_num);
        ++n;
    }
    return jacobsthal_numbers;
}

template <typename Container>
void insert_with_jacobsthal_binary_search(Container &sorted, Container &smaller, const std::pair<Container, Container> &pair)
{
    if (smaller.empty()) return;

    typename Container::value_type value = smaller.front();
    typename Container::const_iterator it1 = pair.first.begin();
    typename Container::const_iterator it2 = pair.second.begin();
    typename Container::value_type limit;

    while (it1 != pair.first.end() && it2 != pair.second.end())
    {
        if (value == *it1)
        {
            limit = *it1;
            break;
        }
        else if (value == *it2)
        {
            limit = *it2;
            break;
        }
        ++it1;
        ++it2;
    }

    typename Container::iterator limit_it = std::find(sorted.begin(), sorted.end(), limit);

    std::vector<int> jacobsthal_numbers = generate_jacobsthal_numbers(std::distance(sorted.begin(), limit_it));

    typename Container::iterator it = sorted.begin();
    int low = 0;
    int high = jacobsthal_numbers.size() - 1;

    while (low <= high)
    {
        int mid_index = (low + high) / 2;
        typename Container::iterator mid = sorted.begin();
        std::advance(mid, jacobsthal_numbers[mid_index]);
        comparision_count++;
        if (*mid < value)
        {
            it = mid;
            ++it;
            low = mid_index + 1;
        }
        else
            high = mid_index - 1;
    }

    sorted.insert(it, value);
    smaller.erase(smaller.begin());
}


template <typename Container>
void merge(Container &left, Container &right, Container &result)
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
void insert_the_smallest(Container &sorted, Container &smaller, Container &larger, const std::pair<Container, Container> &pair)
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
            if (*it > *next_it)
            {
                pair.first.push_back(*it);
                pair.second.push_back(*next_it);
            }
            else
            {
                pair.first.push_back(*next_it);
                pair.second.push_back(*it);
            }
            it = next_it;
        }
        else
        {
            pair.second.push_back(*it);
        }
    }
    
    Container larger, smaller;
    split_array(pair, larger, smaller);

    merge_sort(larger);

    Container sorted;
    sorted = larger;
    
    insert_the_smallest(sorted, smaller, larger, pair);

    while (!smaller.empty())
    {
        insert_with_jacobsthal_binary_search(sorted, smaller, pair);
    }

    array = sorted;
    //std::cout << "Comparision count: " << comparision_count << std::endl;
    comparision_count = 0;
}

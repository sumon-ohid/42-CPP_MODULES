/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:27:43 by msumon            #+#    #+#             */
/*   Updated: 2024/08/16 07:27:44 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <stdexcept>

// Function to merge two sorted halves
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    unsigned int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftArr.size())
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size())
    {
        arr[k++] = rightArr[j++];
    }
}

// Ford-Johnson sorting algorithm
void fordJohnsonSort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        fordJohnsonSort(arr, left, mid);
        fordJohnsonSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main(int argc, char const **argv)
{
    try
    {
        if (argc < 2)
        {
            throw std::invalid_argument("No positive integer sequence provided.");
        }

        std::vector<int> arr;
        for (int i = 1; i < argc; ++i)
        {
            int num = std::atoi(argv[i]);
            if (num <= 0) {
                throw std::invalid_argument("All numbers must be positive integers.");
            }
            arr.push_back(num);
        }

        if (arr.size() > 3000)
        {
            throw std::invalid_argument("The sequence must contain at most 3000 integers.");
        }

        std::cout << "Before: ";
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::clock_t start = std::clock();
        fordJohnsonSort(arr, 0, arr.size() - 1);
        std::clock_t end = std::clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "After: ";
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) 
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << duration * 1e6 << " us" << std::endl;

        // Using a different container (deque) for validation
        std::deque<int> dequeArr(arr.begin(), arr.end());

        start = std::clock();
        std::sort(dequeArr.begin(), dequeArr.end()); // Using std::sort for simplicity
        end = std::clock();
        duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << duration * 1e6 << " us" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
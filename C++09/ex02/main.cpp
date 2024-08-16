/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:27:43 by msumon            #+#    #+#             */
/*   Updated: 2024/08/16 10:06:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const **argv)
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("");
        std::vector<int> arr;
        for (int i = 1; i < argc; ++i)
        {
            int num = std::atoi(argv[i]);
            if (num <= 0)
                throw std::invalid_argument("");
            arr.push_back(num);
        }
        if (arr.size() > 3000)
            throw std::invalid_argument("");
        
        std::cout << "Before: ";
        int i = 0;
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        {
                
            std::cout << *it << " ";
            i++;
            if (i == 4 && argc > 5)
            {
                std::cout << " [...]";
                i = 0;
                break;
            }
        }
        std::cout << std::endl;

        std::clock_t start = std::clock();
        fordJohnsonSort(arr, 0, arr.size() - 1);
        std::clock_t end = std::clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "After: ";
        i = 0;
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) 
        {
            std::cout << *it << " ";
            i++;
            if (i == 4 && argc > 5)
            {
                std::cout << " [...]";
                i = 0;
                break;
            }
        }
        std::cout << std::endl;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << duration * 1e3 << " us" << std::endl;

        // Using a different container (deque) for validation
        std::deque<int> dequeArr(arr.begin(), arr.end());

        start = std::clock();
        fordJohnsonSort(arr, 0, arr.size() - 1);
        end = std::clock();
        duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << duration * 1e3 << " us" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << e.what() << std::endl;
        return 1;
    }

    return 0;
}
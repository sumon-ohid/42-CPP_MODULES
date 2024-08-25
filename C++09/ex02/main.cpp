/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 07:27:43 by msumon            #+#    #+#             */
/*   Updated: 2024/08/25 10:15:11 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool hasRepetition(const std::vector<int> &array)
{
    for (int i = 0; i < (int)array.size(); ++i)
    {
        if (std::count(array.begin(), array.end(), array[i]) > 1)
            return true;
    }
    return false;
}

int main(int argc, char const **argv)
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("");
        std::vector<int> _array;
        for (int i = 1; i < argc; ++i)
        {
            std::string str(argv[i]);
            if (find(str.begin() + 1, str.end(), '.') != str.end())
                throw std::invalid_argument("");
            if (str.find_first_not_of("0123456789") != std::string::npos)
                throw std::invalid_argument("");
            int num = std::atoi(argv[i]);
            if (num <= 0)
                throw std::invalid_argument("");
            _array.push_back(num);
        }
        if (_array.size() > 30000)
            throw std::invalid_argument("");
        if (hasRepetition(_array))
            throw std::invalid_argument("");
        
        std::cout << "Before : ";
        for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        //Using a different container (list) for validation
        std::deque<int> deque(_array.begin(), _array.end());

        //Using std::vector for sorting    
        std::clock_t start = std::clock();
        fordJohnsonSort(_array);
        std::clock_t end = std::clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "After  : ";
        for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); ++it) 
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << std::fixed << std::setprecision(6) << duration * 1e3 << " us" << std::endl;
        
        //Using std::deque for sorting
        start = std::clock();
        fordJohnsonSort(deque);
        end = std::clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << std::fixed << std::setprecision(6) << duration * 1e3 << " us" << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

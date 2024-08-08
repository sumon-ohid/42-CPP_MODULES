/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:54 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 14:56:05 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    Array<int> arr1(5);
    std::cout << "Parameterized Constructor - Size: " << arr1.size() << std::endl;

    std::cout << std::endl;
    Array<int> arr2;
    std::cout << "Default Constructor - Size: " << arr2.size() << std::endl;

    std::cout << std::endl;
    Array<int> arr3(arr1);
    std::cout << "Copy Constructor - Size: " << arr3.size() << std::endl;

    std::cout << std::endl;
    arr2 = arr1;
    std::cout << "Assignment Operator - Size: " << arr2.size() << std::endl;

    for (unsigned int i = 0; i < arr1.size(); ++i) 
    {
        arr1[i] = i * 10;
    }
    std::cout << std::endl;
    std::cout << "Subscript Operator - Elements: ";
    for (unsigned int i = 0; i < arr1.size(); ++i) 
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    try
    {
        std::cout << "Error Test Accessing element at index 10: ";
        std::cout << arr1[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Size of arr1: " << arr1.size() << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << std::endl;
    return 0;
}

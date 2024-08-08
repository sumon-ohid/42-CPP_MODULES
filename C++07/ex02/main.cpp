/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:54 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 12:24:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <exception>
#include <iostream>

int main(void)
{
    Array<int> arr1(5);
    std::cout << "Test 1: Parameterized Constructor - Size: " << arr1.size() << std::endl;

    Array<int> arr2;
    std::cout << "Test 2: Default Constructor - Size: " << arr2.size() << std::endl;

    Array<int> arr3(arr1);
    std::cout << "Test 3: Copy Constructor - Size: " << arr3.size() << std::endl;

    arr2 = arr1;
    std::cout << "Test 4: Assignment Operator - Size: " << arr2.size() << std::endl;

    for (unsigned int i = 0; i < arr1.size(); ++i) 
    {
        arr1[i] = i * 10;
    }
    std::cout << "Test 5: Subscript Operator - Elements: ";
    for (unsigned int i = 0; i < arr1.size(); ++i) 
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Test 6: Out of Range Access - Accessing element at index 10: ";
        std::cout << arr1[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Test 7: Size Method - Size of arr1: " << arr1.size() << std::endl;

    return 0;
}

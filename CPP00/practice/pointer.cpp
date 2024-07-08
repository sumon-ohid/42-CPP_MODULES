/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:10:17 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 19:03:22 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    char *ptr = new char;
    printf("%p\n", ptr);
    delete ptr;

    std::string food = "Pizza";
    std::string *meal = &food;

    std::cout << "Value of food: " << food << std::endl;
    std::cout << "Value of meal: " << *meal << std::endl;
    std::cout << "Memory address of food: " << &food << std::endl;
    std::cout << "Memory address of meal: " << meal << std::endl;

    *meal = "Hamburger";
    std::cout << "Modify pointer" << std::endl;
    std::cout << "Value of food: " << food << std::endl;
    std::cout << "Value of meal: " << *meal << std::endl;
    std::cout << "Memory address of food: " << &food << std::endl;
    std::cout << "Memory address of meal: " << meal << std::endl;
    return (0);
}

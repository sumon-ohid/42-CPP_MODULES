/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/07/31 10:17:20 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    while (std::cin)
    {
        std::string name;
        int grade;
        std::cout << "Enter Name  : ";
        std::cin >> name;
        std::cout << "Enter Grade : ";
        std::cin >> grade;
        try
        {
            Bureaucrat b1(name, grade);
            std::cout << b1.getName();
            std::cout << ", bureaucrat grade ";
            std::cout << b1.getGrade() << "." << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}



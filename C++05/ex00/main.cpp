/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/07/31 15:52:52 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    std::string name = "Sabbi";
    int grade = 10;
    std::cout << std::endl;
    
    // Basic
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
    std::cout << std::endl;
    
    // invalid
    try
    {
        Bureaucrat bono("Alex", -42);
        std::cout << bono.getName();
        std::cout << ", bureaucrat grade ";
        std::cout << bono.getGrade() << "." << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    //increment
    try
    {
        Bureaucrat bonono("Pmik", 3);
        bonono.increment();
        std::cout << bonono.getName();
        std::cout << ", bureaucrat grade ";
        std::cout << bonono.getGrade() << "." << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    //decrement
    try
    {
        Bureaucrat bnno("Mono", 10);
        bnno.decrement();
        std::cout << bnno.getName();
        std::cout << ", bureaucrat grade ";
        std::cout << bnno.getGrade() << "." << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    // Decrement
    try
    {
        Bureaucrat bobby("Bobby", 100);
        bobby.decrement();
        std::cout << bobby.getName();
        std::cout << ", bureaucrat grade ";
        std::cout << bobby.getGrade() << "." << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

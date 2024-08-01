/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 15:12:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("Sami", 1);
        Form form("Nebula", 15, 15);
        bureaucrat.increment();
        bureaucrat.signForm(form);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat("Sopppy", 10);
        Form form("Nebula", 15, 15);
        bureaucrat.decrement();
        bureaucrat.signForm(form);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat("Sopppy", 10);
        Form form("Nebula", 15, 15);
        bureaucrat.decrement();
        bureaucrat.signForm(form);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat bureaucrat("Delip", 120);
        Form form("Nebula", 15, 15);
        bureaucrat.decrement();
        bureaucrat.signForm(form);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:42:53 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 17:17:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable. I want to speak to the manager." << std::endl;
}

void Harl::complain( std::string level )
{
    int i = 0;
    Harl harl;
    std::string levels[4] = 
    {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };
    
    void (Harl::*complaints[4])( void ) = 
    {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };
    
    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            break;
        }
    }
    switch (i)
    {
        case 0:
            harl.debug();
        case 1:
            harl.info();
        case 2:
            harl.warning();
        case 3:
            harl.error();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
    }
    return;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:41:14 by msumon            #+#    #+#             */
/*   Updated: 2024/07/18 22:58:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap claptrap;
    ClapTrap claptrap1("Cobra");
    ClapTrap claptrap2(claptrap);
    
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::endl;
        claptrap1.attack("enemy");
        claptrap1.takeDamage(5);
        std::cout << "Hitpoints remains : " << claptrap1.getHitpoints() << std::endl;
        std::cout << "EnergyPoints remains : " << claptrap1.getEnergyPoints() << std::endl;
        claptrap1.beRepaired(5);
        std::cout << "Hitpoints remains : " << claptrap1.getHitpoints() << std::endl;
        std::cout << "EnergyPoints remains : " << claptrap1.getEnergyPoints() << std::endl;
        std::cout << std::endl;
    }
    return (0);
}
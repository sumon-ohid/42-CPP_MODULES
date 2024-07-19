/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:41:14 by msumon            #+#    #+#             */
/*   Updated: 2024/07/19 20:07:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ScavTrap scavtrap;
    ScavTrap scavTrap("Norminette");
    scavTrap.attack("target");
    scavTrap.takeDamage(5);
    std::cout << scavTrap << std::endl;
    scavTrap.beRepaired(5);
    scavTrap.guardGate();

    std::cout << std::endl;
    std::cout << scavTrap << std::endl;

    ScavTrap scavTrap1("Moulinette");
    scavTrap1.attack("target");
    scavTrap1.takeDamage(5);
    scavTrap1.beRepaired(5);
    scavTrap1.guardGate();

    std::cout << std::endl;
    std::cout << scavTrap1 << std::endl;
    
    return (0);
}
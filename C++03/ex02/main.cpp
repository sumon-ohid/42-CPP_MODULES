/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:41:14 by msumon            #+#    #+#             */
/*   Updated: 2024/07/22 12:27:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap Fragtrap;
    class FragTrap FragTrap("Master yi");
    FragTrap.attack("Yasuo");
    FragTrap.takeDamage(5);
    std::cout << FragTrap << std::endl;
    FragTrap.beRepaired(5);
    FragTrap.highFivesGuys();

    std::cout << std::endl;
    std::cout << FragTrap << std::endl;

    class FragTrap FragTrap1("Zed");
    FragTrap1.attack("Draven");
    FragTrap1.takeDamage(5);
    FragTrap1.beRepaired(5);
    FragTrap1.highFivesGuys();

    std::cout << std::endl;
    std::cout << FragTrap1 << std::endl;
    
    return (0);
}
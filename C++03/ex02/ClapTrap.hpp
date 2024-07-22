/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:39:43 by msumon            #+#    #+#             */
/*   Updated: 2024/07/19 20:04:33 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energyPoints;
        int attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &copy);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getHitpoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &clapTrap);
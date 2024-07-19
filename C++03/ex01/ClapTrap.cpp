/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:40:00 by msumon            #+#    #+#             */
/*   Updated: 2024/07/19 20:04:22 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ClapTrap Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ClapTrap Parameterized constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap Copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hitpoints = copy.hitpoints;
    this->energyPoints = copy.energyPoints;
    this->attackDamage = copy.attackDamage;
    std::cout << "ClapTrap Assignation operator" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitpoints > 0 && energyPoints > 0)
    {
        energyPoints -= 1;
        std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " cannot attack due to insufficient hit points or energy points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitpoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can not take more damage!" << std::endl;
        return ;
    }
    hitpoints -= amount;
    std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitpoints > 0 && energyPoints > 0)
    {
        energyPoints -= 1;
        hitpoints += amount;
        std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " cannot be repaired due to insufficient hit points or energy points." << std::endl;
}

int ClapTrap::getHitpoints() const
{
    return (hitpoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (energyPoints);
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &clapTrap)
{
    out << "ClapTrap hitpoints: " << clapTrap.getHitpoints() << std::endl;
    out << "ClapTrap energy points: " << clapTrap.getEnergyPoints() << std::endl;
    return (out);
}

int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:27:27 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 12:42:57 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name): name(name)
{ 
    this->weapon = NULL; 
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (this->weapon == NULL)
        std::cout << this->name << " has no weapon to attack with" << std::endl;
    else
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
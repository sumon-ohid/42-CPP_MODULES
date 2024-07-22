/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:54:13 by msumon            #+#    #+#             */
/*   Updated: 2024/07/22 12:29:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Parameterized constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap Assignation operator" << std::endl;
    if(this == &copy)
        return (*this);
    ClapTrap::operator=(copy);
    return (*this);
}

FragTrap :: ~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << "high fives guys" << std::endl;
}

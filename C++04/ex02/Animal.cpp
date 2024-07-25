/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:26 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 12:59:26 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "🦧🦧 Animal Default Constructor 🦧🦧" << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
}

Animal::Animal(Animal &copy)
{
    *this = copy;
}

Animal &Animal::operator=(Animal &copy)
{
    type = copy.type;
    return (*this);
}

Animal:: ~Animal()
{
    std::cout << "🦧🦧 Animal Destructor 🦧🦧" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
    return(type);
}
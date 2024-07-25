/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:26 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:29:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "❌ Here is WrongAnimal Default Constructor ❌" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &copy)
{
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

WrongAnimal:: ~WrongAnimal()
{
    std::cout << "❌ Here is WrongAnimal Destructor ❌" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type);
}
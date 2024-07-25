/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:36 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:25:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "😺😺 Cat default Constructor Activated 😺😺" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
}

Cat::Cat(Cat &copy) : Animal(copy)
{
}

Cat &Cat::operator=(Cat &copy)
{
    type = copy.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "😺😺 Cat Destructor Activated 😺😺" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Mewwww Mewwww" << std::endl;
}

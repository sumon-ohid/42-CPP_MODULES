/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:36 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 18:02:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal() , _brain(new Brain)
{
    type = "Cat";
    std::cout << "😺😺 Cat default Constructor Activated 😺😺" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
}

Cat::Cat(Cat &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
}

Cat &Cat::operator=(Cat &copy)
{
    if (this != &copy)
    {
        delete _brain;
        _brain = new Brain(*copy._brain);
        Animal::operator=(copy);
    }
    return (*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "😺😺 Cat Destructor Activated 😺😺" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Mewwww Mewwww" << std::endl;
}

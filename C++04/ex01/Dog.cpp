/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:42 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 15:55:48 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal(), _brain(new Brain)
{
    type = "Dog";
    std::cout << "🐶🐶 Dog default Constructor is Called 🐶🐶" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
}

Dog::Dog(Dog &copy) : Animal(copy), _brain(new Brain(*copy._brain))
{   
}

Dog &Dog::operator=(Dog &copy)
{
    type = copy.type;
    return (*this);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "🐶🐶 Dog Destructor is Called 🐶🐶" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Woooof Woof" << std::endl;
}

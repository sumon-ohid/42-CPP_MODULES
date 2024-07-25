/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:27:19 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:33:33 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "❌😺 WrongCat default Constructor Activated ❌😺" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy)
{
}

WrongCat &WrongCat::operator=(WrongCat &copy)
{
    type = copy.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "❌😺 WrongCat Destructor Activated ❌😺" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: Mewwww Mewwww ❌" << std::endl;
}

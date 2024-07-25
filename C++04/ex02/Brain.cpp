/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:14:29 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 17:52:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = " Creative Idea ";
    }
    std::cout << "🧠 Brain Constructor Brainzzzz 🧠" << std::endl;
}

Brain::Brain(Brain &copy)
{
    std::cout << "🧠 Brain Copy Constructor Brainzzzz 🧠" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator=(Brain &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "🧠 Brain Destructor Brainzzzz 🧠" << std::endl;
}

void Brain::setIdea(int index, std::string ideas)
{
    this->ideas[index] = ideas;
}

std::string Brain::getIdea(int index)
{
    return (ideas[index]);
}

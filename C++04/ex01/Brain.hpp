/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:14:20 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 16:42:10 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Animal.hpp"

class Brain : public Animal
{
    protected:
        std::string ideas[100];

    public:
        Brain();
        Brain(Brain &copy);
        Brain &operator=(Brain &copy);
        ~Brain();

        void setIdea(int index, std::string idea);
};
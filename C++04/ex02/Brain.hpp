/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:14:20 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 17:52:08 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain
{
    protected:
        std::string ideas[100];

    public:
        Brain();
        Brain(Brain &copy);
        Brain &operator=(Brain &copy);
        ~Brain();

        void setIdea(int index, std::string idea);
        std::string getIdea(int index);
};

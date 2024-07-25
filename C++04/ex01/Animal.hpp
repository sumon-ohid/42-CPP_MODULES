/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:11:52 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:16:25 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal &copy);
        Animal &operator=(Animal &copy);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

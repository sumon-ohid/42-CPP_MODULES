/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:45 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 12:52:35 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{ 
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog &copy);
        Dog &operator=(Dog &copy);
        ~Dog();

        void makeSound() const override;
};

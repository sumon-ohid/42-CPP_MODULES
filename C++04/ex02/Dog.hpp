/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:45 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 17:06:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(std::string type);
        Dog(Dog &copy);
        Dog &operator=(Dog &copy);
        ~Dog();

        virtual void makeSound() const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:39 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 17:06:43 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat &copy);
        Cat &operator=(Cat &copy);
        ~Cat();

        virtual void makeSound() const;
};

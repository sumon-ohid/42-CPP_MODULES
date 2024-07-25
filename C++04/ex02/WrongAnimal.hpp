/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:27:58 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:29:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal
{
    protected:
        std::string type;
        
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal &copy);
        WrongAnimal &operator=(WrongAnimal &copy);
        virtual ~WrongAnimal();

        virtual void makeSound() const;
        std::string getType() const;
};

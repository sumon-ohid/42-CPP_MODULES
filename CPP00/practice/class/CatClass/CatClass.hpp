/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:45:36 by msumon            #+#    #+#             */
/*   Updated: 2024/07/05 10:01:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCLASS_H
# define CATCLASS_H

# include <iostream>

class CatClass
{
    private:
        std::string name;
        std::string color;
        std::string favorite_food;

    public:
        void print_cat()
        {
            std::cout << "Cat name :" << name << std::endl;
            std::cout << "Cat color :" << color << std::endl;
            std::cout << "Cat favorite food :" << favorite_food << std::endl;
        }
        CatClass()
        {
            name = "Meaw";
            color = "White";
            favorite_food = "Fish";
        }
        
        CatClass(std::string n)
        {
            name = n;
            color = "White";
            favorite_food = "Fish";
        }
        CatClass(std::string n, std::string c, std::string f_t);
};
CatClass::CatClass(std::string n, std::string c, std::string f_t)
        {
            name = n;
            color = c;
            favorite_food = f_t;
        }

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:48 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 14:41:55 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    //WrongAnimal
    const WrongAnimal *_animal = new WrongAnimal();
    const WrongAnimal *_cat = new WrongCat();
    
    std::cout << std::endl;
    std::cout << "Type : " << j->getType() << " " << std::endl;
    std::cout << "Type : " << i->getType() << " " << std::endl;

    std::cout << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    //WrongCat
    std::cout << std::endl;
    _cat->makeSound();
    _animal->makeSound();

    std::cout << std::endl;
    std::cout << "Wrong Type : " << _cat->getType() << " " << std::endl;
    std::cout << std::endl;
    
    delete meta;
    delete j;
    delete i;

    delete _animal;
    delete _cat;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:48 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 16:32:42 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main(void)
{
    int i = 0;
    Animal *animal[10];
    
    std::cout << std::endl;
    while (i < 5)
    {
        animal[i] = new Dog();

        std::cout << animal[i]->getType() << " " << std::endl;
        animal[i]->makeSound();
        i++;   
    }
    while (i < 10)
    {
        animal[i] = new Cat();

        std::cout << animal[i]->getType() << " " << std::endl;
        animal[i]->makeSound();
        i++;   
    }
    std::cout << std::endl;
    i = 0;
    while (i < 10)
    {
        delete animal[i];
        i++;
    }
    return (0);
}


// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const Animal* j = new Dog();
//     const WrongAnimal* i = new WrongCat();

//     //WrongAnimal
//     const WrongAnimal *_animal = new WrongAnimal();
//     const WrongAnimal *_cat = new WrongCat();
    
//     std::cout << std::endl;
//     std::cout << "Type : " << j->getType() << " " << std::endl;
//     std::cout << "Type : " << i->getType() << " " << std::endl;

//     std::cout << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     //WrongCat
//     std::cout << std::endl;
//     _cat->makeSound();
//     _animal->makeSound();

//     std::cout << std::endl;
//     std::cout << "Wrong Type : " << _cat->getType() << " " << std::endl;
//     std::cout << std::endl;
    
//     delete meta;
//     delete j;
//     delete i;

//     delete _animal;
//     delete _cat;
//     return 0;
// }

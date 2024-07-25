/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtype_polymorphysm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:37:11 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 11:59:42 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//Abstruct class
//This is an abstract class because it has a pure virtual function.
class Abstruct
{
    public:
        virtual void print() const = 0;
};

//base class
class Animal
{
    public:
        virtual void makeSound() const
        {
            std::cout << "Animal Sound" << std::endl;
        }
};

//Derived class
class Dog : public Animal
{
    public:
        void makeSound() const override
        {
            std::cout << "Wooof" << std::endl;
        }
};

//Derived class
class Cat : public Animal
{
    public:
        void makeSound() const override
        {
            std::cout << "Mewww" << std::endl;
        }
};

// When pass an object by reference
// the actual object (or a derived class object) is used.
// This allows polymorphism to work correctly.
// If animal is actually an instance of a derived class.
// the correct version of makeSound() will be called.
void playSound(const Animal &animal)
{
    animal.makeSound();
}

class Foo
{
    public:
        virtual void print() const
        {
            std::cout << "I am Foo class" << std::endl;
        }
};

int main()
{
    Dog dog;
    Cat cat;
    
    Foo *foo = new Foo;

    playSound(dog);
    playSound(cat);

    foo->print();
    delete foo;
    return (0);
}
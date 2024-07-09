/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:28:07 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 11:22:36 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
    //OnHeap
    // it's suitable for long-lived objects with an unknown lifetime
    // when the size of the object is unknown at compile time.
    // large objects are usually allocated on the heap
    Zombie *onHeap1 = newZombie("Zomboheap");
    onHeap1->announce();

    //OnStack
    // it's suitable for short-lived objects with a known lifetime
    // it's faster than onHeap
    Zombie onStack1("Zombostack");
    onStack1.announce();

    //RandomChump
    //std::cout << "RandomChump is called" << std::endl;
    randomChump("Zomborandom");
    
    delete(onHeap1); // free after use

    return (0);
}

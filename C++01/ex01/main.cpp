/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:15:07 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 11:52:22 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie *zombie = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
    delete [] zombie;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:37:42 by msumon            #+#    #+#             */
/*   Updated: 2024/05/02 22:50:44 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;
    
    i = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        i = 1;
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
                std::cout << (char) toupper(av[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:27:47 by msumon            #+#    #+#             */
/*   Updated: 2024/07/19 15:34:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./a.out filename" << std::endl;
        return (1);
    }
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.close();
    return (0);
}

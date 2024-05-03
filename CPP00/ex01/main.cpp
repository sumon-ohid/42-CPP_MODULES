/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:15:04 by msumon            #+#    #+#             */
/*   Updated: 2024/05/03 10:47:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.hpp"

int main()
{
    int input;

    input = 0;
    std::cout << "1. ADD - add new contact.\n";
    std::cout << "2. SEARCH - search existing contact.\n";
    std::cout << "3. EXIT - quit program.\n";

    while (1)
    {
        std::cout << "PLEASE CHOOSE : ";
        std::cin >> input;
        if (input == 1)
            add_contact();
        else if (input == 2)
            search_contact();
        else if (input == 3)
        {
            std::cout << "Good Bye !!!\n";
            break;
        }
        else
            std::cout << "PLEASE ENTER A VALID INPUT !!\n";
    }
    return (0);
}

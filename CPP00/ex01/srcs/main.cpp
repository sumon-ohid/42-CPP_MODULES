/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:15:04 by msumon            #+#    #+#             */
/*   Updated: 2024/05/03 11:24:15 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

void Welcome(void)
{
    std::cout << "\033[1;32m";
    std::cout <<    "*-------------------------------------------*\n"
                    "|                                           |\n"
                    "|              PhoneBook 1980s              |\n"  
                    "|                                           |\n"
                    "|          ADD - Add a new contact          |\n"
                    "|          SEARCH - Display a contact       |\n"
                    "|          EXIT - Quit PhoneBook            |\n"
                    "|                                           |\n"
                    "*-------------------------------------------*" << std::endl;
    std::cout << "\033[0m";
}

int	main(void)
{
	PhoneBook	phonebook;
	int index;

    Welcome();
	while (true)
	{
        std::cout << "\033[1;32m";
        std::cout << "--->> ";
		std::string command;
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (command == "ADD")
		{
			std::string first_name, last_name, nickname, phone_number,
				darkest_secret;
			std::cout << "Enter First Name: ";
			std::cin >> first_name;
			std::cout << "Enter Last Name: ";
			std::cin >> last_name;
			std::cout << "Enter Nickname: ";
			std::cin >> nickname;
			std::cout << "Enter Phone Number: ";
			std::cin >> phone_number;
			std::cout << "Enter Darkest Secret: ";
			std::cin >> darkest_secret;
			Contact new_contact(first_name, last_name, nickname, phone_number,
				darkest_secret);
			phonebook.addContact(new_contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			std::cout << "Enter Index: ";
			std::cin >> index;
            if (!std::cin || index < 0 || index > 7)
            {
                std::cerr << "Error: Input is either not a valid number or not within the range 0-7.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                phonebook.searchContact(index);
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting program..." << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command! Try again." << std::endl;
		}
	}
	return (0);
}

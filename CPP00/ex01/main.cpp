/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:15:04 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 17:51:34 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

void Welcome(void)
{
    std::cout << "\033[1;32m";
    std::cout <<    " ___________________________________________\n"
                    "|                                           |\n"
                    "|          ADD     - Add a new contact      |\n"
					"|___________________________________________|\n"
					"|                                           |\n"
                    "|          SEARCH  - Display a contact      |\n"
					"|___________________________________________|\n"
					"|                                           |\n"
                    "|          EXIT    - Exit PhoneBook         |\n"
                    "|___________________________________________|" << std::endl;
    std::cout << "\033[0m";
}

static int is_all_alpha(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (0);
	}
	return (1);
}

static int is_all_digits(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

void error_msg(const std::string &msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

static void add_new_contact(PhoneBook &PhoneBook)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, first_name);
	if (!is_all_alpha(first_name))
	    return (error_msg("First name must be alphabetic."));
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, last_name) ;
	if (!is_all_alpha(last_name))
	    return (error_msg("Last name must be alphabetic."));
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	if (!is_all_alpha(nickname))
	    return (error_msg("Nickname must be alphabetic."));
	std::cout << "Enter Phone Number (10 digits): (+43) ";
	std::getline(std::cin, phone_number);
	if (phone_number.length() != 10 || !is_all_digits(phone_number))
	    return(error_msg("Phone number must be 10 digits."));
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.length() == 0)
	    return (error_msg("Darkest secret cannot be empty."));
	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	PhoneBook.addContact(new_contact);
}

static void search_in_phonebook(PhoneBook &PhoneBook)
{
	int index;
	std::string index_str;

	PhoneBook.displayContacts();
	std::cout << "Enter index of the contact: ";
	std::getline(std::cin, index_str);
	if (index_str.length() != 1 || !isdigit(index_str[0]))
	{
		std::cerr << "Error: Invalid index." << std::endl;
		return ;
	}
	index = index_str[0] - '0';
	PhoneBook.searchContact(index);
}

int	main(void)
{
	PhoneBook	phonebook;

    Welcome();
	while (true)
	{
        std::cout << "--->> ";
		std::string command;
		std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
		std::getline (std::cin, command);
		if (command == "ADD")
			add_new_contact(phonebook);
		else if (command == "SEARCH")
		    search_in_phonebook(phonebook);
		else if (command == "EXIT")
		{
			std::cout << "Exiting program..." << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command! Try again." << std::endl;
	}
	return (0);
}

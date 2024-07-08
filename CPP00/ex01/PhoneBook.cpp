/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:20:58 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 06:26:56 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    num_contacts = 0;
}

void PhoneBook::addContact(const Contact &contact)
{
	int num_contacts = this->num_contacts;
	
	if (num_contacts < 8)
	{
		contacts[num_contacts] = contact;
		num_contacts++;
	}
	else
	{
		contacts[0] = contact;
	}
}

void PhoneBook::searchContact(int index)
{
	if (index < 0 || index >= this->num_contacts)
	{
		std::cout << "Contact does not exist!" << std::endl;
		return ;
	}
	contacts[index].display();
}

std::string format_string(const std::string &str)
{
	std::string result;
	if (str.length() < 10)
	{
		return (str + std::string(10 - str.length(), ' '));
	}
	else
	{
		result = str.substr(0, 9);
		result += ".";
	}
	return (result);
}

void PhoneBook::displayContacts()
{
	std::cout << "     Index|First Name| Last Name| Nick Name|" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << format_string(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << format_string(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << std::right << format_string(contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}		
}
    
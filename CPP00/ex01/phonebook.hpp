/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:07:08 by msumon            #+#    #+#             */
/*   Updated: 2024/07/05 21:56:51 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

void Welcome(void);

class PhoneBook
{
  private:
	Contact contacts[8];
	int num_contacts;

  public:
	PhoneBook() : num_contacts(0)
	{
	}

	void addContact(const Contact &contact)
	{
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

	void searchContact(int index)
	{
		if (index < 0 || index >= num_contacts)
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

	void displayContacts()
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
};

#endif
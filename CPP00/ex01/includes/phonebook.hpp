/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:07:08 by msumon            #+#    #+#             */
/*   Updated: 2024/05/03 10:58:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include <iostream>

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
			contacts[num_contacts++] = contact;
		}
		else
		{
			// Replace the oldest contact
			for (int i = 0; i < 7; ++i)
			{
				contacts[i] = contacts[i + 1];
			}
			contacts[7] = contact;
		}
	}

	void searchContact(int index) const
	{
		if (index < 0 || index >= num_contacts)
		{
			std::cout << "Invalid index!" << std::endl;
			return ;
		}

		contacts[index].display();
	}

	void displayContacts() const
	{
		std::cout << std::setw(10) << std::right << "Index"
					<< " | " << std::setw(10) << std::right << "First Name"
					<< " | " << std::setw(10) << std::right << "Last Name"
					<< " | " << std::setw(10) << std::right << "Nickname" << std::endl;

		for (int i = 0; i < num_contacts; ++i)
		{
			std::cout << std::setw(10) << std::right << i << " | " << std::setw(10) << std::right << truncateString(contacts[i].getFirstName(),
				10) << " | " << std::setw(10) << std::right << truncateString(contacts[i].getLastName(),
				10) << " | " << std::setw(10) << std::right << truncateString(contacts[i].getNickname(),
				10) << std::endl;
		}
	}

  private:
	std::string truncateString(const std::string &str, int length) const
	{
		if (str.length() > length)
		{
			return (str.substr(0, length - 1) + ".");
		}
		return (str);
	}
};

#endif
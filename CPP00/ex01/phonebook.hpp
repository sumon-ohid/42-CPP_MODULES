/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:07:08 by msumon            #+#    #+#             */
/*   Updated: 2024/07/04 18:52:53 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include <iostream>

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
			contacts[num_contacts++] = contact;
		}
		else
		{
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
		std::cout << "Index   |   First Name | Last Name  | Nick Name" << std::endl;
		std::cout << "  0    " << contacts[0].displayContacts() <<
	}
};

#endif
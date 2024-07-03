/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:07:05 by msumon            #+#    #+#             */
/*   Updated: 2024/05/03 11:10:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact()
	{
	}

	Contact(std::string first_name, std::string last_name, std::string nickname,
		std::string phone_number,
		std::string darkest_secret) : first_name(first_name),
		last_name(last_name), nickname(nickname), phone_number(phone_number),
		darkest_secret(darkest_secret)
	{
	}

	void display() const
	{
		std::cout << "First Name: " << first_name << std::endl;
		std::cout << "Last Name: " << last_name << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone Number: " << phone_number << std::endl;
		std::cout << "Darkest Secret: " << darkest_secret << std::endl;
	}

	std::string getFirstName() const
	{
		return (first_name);
	}
	std::string getLastName() const
	{
		return (last_name);
	}
	std::string getNickname() const
	{
		return (nickname);
	}
};

#endif
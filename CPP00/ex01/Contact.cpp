/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:31:27 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 06:40:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first, std::string last, std::string nick,
    std::string phone_number, std::string darkest_secret)
{
    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone_number;
    darkest_secret = darkest_secret;
}

void Contact::display() const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

std::string Contact::get_first_name() const
{
	return (first_name);
}
std::string Contact::get_last_name() const
{
	return (last_name);
}
std::string Contact::get_nickname() const
{
	return (nickname);
}
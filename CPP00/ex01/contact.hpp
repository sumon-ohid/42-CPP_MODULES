/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:07:05 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 18:00:25 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

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
	Contact();
	Contact(std::string first, std::string last, std::string nick,
		std::string phone_num, std::string secret);
	void display() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
};

#endif
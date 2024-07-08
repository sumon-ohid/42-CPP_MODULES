/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:26:23 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 18:59:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string firstName = "Sumon";
    std::string lastName = "Oahid";
    std::string fullName = firstName + " " + lastName;

    std::cout << "+ method --> " << fullName << std::endl; // + method

    fullName = firstName.append(lastName);
    std::cout << "append method --> " << fullName << std::endl; // append method

    std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = txt.length();
    int size = txt.size();
    std::cout << "Length of txt is: " << length << std::endl; // length method
    std::cout << "Size of txt is: " << size << std::endl;
    std::cout << "at method --> " << txt.at(25) << std::endl; // at method

    std::cout << "My name is \"Sumon\" Oahid" << std::endl; // escape character

    std::cout << &txt << std::endl; // memory address
    return 0;
}

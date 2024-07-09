/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:08:05 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 12:11:11 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "Address of the string: " << &str << std::endl;
    std::cout << "Address of the pointer: " << ptr << std::endl;
    std::cout << "Address of the reference: " << &ref << std::endl;

    std::cout << "String: " << str << std::endl;
    std::cout << "Pointer: " << *ptr << std::endl;
    std::cout << "Reference: " << ref << std::endl;
    return (0);
}

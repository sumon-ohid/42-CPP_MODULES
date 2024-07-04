/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostreams.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:14:50 by msumon            #+#    #+#             */
/*   Updated: 2024/07/04 11:28:39 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    char buff[255];

    std::cout << "Hello World" << std::endl;
    std::cout << "Input a word : ";
    std::cin >> buff;
    std::cout << "You entered --> [" << buff << "]" << std::endl;
    return (0);
}

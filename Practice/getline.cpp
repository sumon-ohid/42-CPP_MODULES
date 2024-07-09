/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:01 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 16:45:53 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string line;

    std::cout << "Enter a line of text: ";
    std::getline (std::cin, line);

    std::cout << "You entered: " << line << std::endl;

    return 0;
}

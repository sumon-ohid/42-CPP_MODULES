/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:09:57 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 19:12:29 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void myFunction()
{
    std::cout << "I just got executed!" << std::endl;
}

void myFunction(std::string country)
{
    std::cout << country << " is my country" << std::endl;
}

void myFunction(int x)
{
    std::cout << "I am " << x << " years old" << std::endl;
}

int main()
{
    myFunction();
    myFunction("Bangladesh");
    myFunction(27);
    return 0;
}

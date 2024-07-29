/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:05:59 by msumon            #+#    #+#             */
/*   Updated: 2024/07/29 10:20:25 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

int main(void)
{
    std::string word = "Hello";

    try
    {
        //std::cout << word.at(10) << std::endl;
        throw std::runtime_error("Problem here");
    }
    // catch (...)
    // {
    //     std::cout << "Error ! something bad happened." << std::endl;
    // }
    catch (std::out_of_range &e)
    {
        std::cout << "First Catch: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Second Catch :: " << e.what() << std::endl;
    }
    return (0);
}

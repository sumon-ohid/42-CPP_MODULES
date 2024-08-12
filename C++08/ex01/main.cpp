/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:21 by msumon            #+#    #+#             */
/*   Updated: 2024/08/12 12:32:21 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(10000);
    
    // Generate 10000 random numbers and add them to numbers vector
    std::srand(std::time(0));
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i)
    {
        numbers.push_back(std::rand());
    }
    
    // Add the numbers to the Span
    std::vector<int>::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        sp.addNumber(*it);
        it++;
    }

    try
    {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

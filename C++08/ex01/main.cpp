/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:21 by msumon            #+#    #+#             */
/*   Updated: 2024/08/12 14:34:25 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << " *** Creating Span with limit 5 ***" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << " *** Creating Span with limit 10000 ***" << std::endl;
    Span sp2 = Span(10000);
    
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
        sp2.addNumber(*it);
        it++;
    }

    try
    {
        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n*** Adding one more number to the Span after limit ***" << std::endl;
    try 
    {
        sp2.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

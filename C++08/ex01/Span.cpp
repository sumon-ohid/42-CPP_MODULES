/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:42:24 by msumon            #+#    #+#             */
/*   Updated: 2024/08/12 15:56:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    N = 0;
}

Span::~Span()
{
}

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::Span(const Span &copy)
{    
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{    
    if (this == &copy)
        return (*this);
    N = copy.N;
    num = copy.num;
    return (*this);
}


void Span::addNumber(int n)
{
    if (num.size() >= N)
    {
        throw std::runtime_error("Error: Vector is full");
    }
    num.push_back(n);
}

int Span::shortestSpan()
{
    if (num.size() <= 1)
        throw std::runtime_error("Error: Not enough elements");
    std::sort(num.begin(), num.end());
    int min = num[1] - num[0];
    for (unsigned int i = 1; i < num.size(); i++)
    {
        if (num[i] - num[i - 1] < min)
            min = num[i] - num[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (num.size() <= 1)
        throw std::runtime_error("Error: Not enough elements");
    std::sort(num.begin(), num.end());
    int max = num[num.size() - 1] - num[0];
    return max;
}

void Span::addManyNumbers(unsigned int _howMany)
{
    if (_howMany == 0 || _howMany > INT_MAX || _howMany > N)
    {
        std::cerr << "Error: Impossible" << std::endl;
        return;
    }
    std::srand(std::time(0));
    for (unsigned int i = 0; i < _howMany; ++i)
    {
        if (num.size() >= N)
            throw std::runtime_error("Error: Span is full");
        num.push_back(std::rand());
    }
}

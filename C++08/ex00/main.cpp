/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:18:49 by msumon            #+#    #+#             */
/*   Updated: 2024/08/12 11:28:52 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        l.push_back(i);
        d.push_back(i);
    }

    std::cout << "*** VECTOR ***" << std::endl;
    v.push_back(42);
    for (int i = 0; i < (int)v.size(); i++)
    {
        std::cout << "Vector [" << i << "] : " << v[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "*** DEQUE ***" << std::endl;
    d.push_front(42);
    d.push_back(42);
    for (int i = 0; i < (int) d.size(); i++)
    {
        std::cout << "Deque [" << i << "] : " << d[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "*** LIST ***" << std::endl;
    l.push_front(42);
    l.push_back(42);
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << "List : " << *it << std::endl;
    }
    
    std::cout << "\n*** RESULT ***" << std::endl;
    testEasyfind(v, 5);
    testEasyfind(l, 5);
    testEasyfind(d, 5);
    testEasyfind(v, 8);
    testEasyfind(l, 8);
    testEasyfind(d, 8);
    testEasyfind(v, 42);
    testEasyfind(l, 42);
    testEasyfind(d, 42);
    testEasyfind(v, 100);
    testEasyfind(l, 100);
    testEasyfind(d, 100);
    return 0;
}

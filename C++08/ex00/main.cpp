/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:18:49 by msumon            #+#    #+#             */
/*   Updated: 2024/08/11 19:23:31 by msumon           ###   ########.fr       */
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

    testEasyfind(v, 5);
    testEasyfind(l, 5);
    testEasyfind(d, 5);
    testEasyfind(v, 10);
    testEasyfind(l, 10);
    testEasyfind(d, 10);
    return 0;
}

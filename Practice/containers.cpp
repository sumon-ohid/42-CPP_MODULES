/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:34:57 by msumon            #+#    #+#             */
/*   Updated: 2024/08/14 10:38:46 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <multimap>

void vector_test()
{
    std::cout << std::endl;
    std::cout << "*** Vector ***" << std::endl;
    int i = 0;
    std::vector<std::string> foods = {"Apple" , "Rice"};
    foods.push_back("Biryani");
    for (auto food : foods)
    {
        std::cout << "index [" << i << "] " << food << std::endl;
        i++;
    }
    std::cout << "Vector size : " << foods.size() << std::endl;
    foods[foods.size()] = "Polao";
    foods[foods.size()] = "Ice cream";
    std::cout << "Vector size : " << foods.size() << std::endl;
    std::cout << foods[foods.size()] << std::endl;
    std::cout << foods[foods.size() - 1] << std::endl;
    foods.pop_back();
    std::cout << foods[foods.size()] << std::endl;
    std::cout << "Vector size : " << foods.size() << std::endl;
    i = 0;
    for (auto food : foods)
    {
        std::cout << "index [" << i << "] " << food << std::endl;
        i++;
    }
}

void deque_test()
{
    std::cout << std::endl;
    int i = 0;
    std::cout << "** Deque ***" << std::endl;
    std::deque<std::string> foods = {"Apple" , "Rice"};
    foods.push_back("Biryani");
    foods.push_front("Khichuri");
    for (auto food : foods)
    {
        std::cout << "index [" << i << "] " << food << std::endl;
        i++;
    }
}

void multimap_test()
{
    std::cout << std::endl;
    std::cout << "*** multimap ***" << std::endl;
    std::multimap <int , int> _multimap;
    _multimap.insert(std::pair<int, int> (0, 42));
    _multimap.insert(std::pair<int, int> (4, 122));
    _multimap.insert(std::pair<int, int> (3, 142));
    _multimap.insert(std::pair<int, int> (5, 542));
    _multimap.insert(std::pair<int, int> (1, 1112));
    _multimap.insert(std::pair<int, int> (6, 432));
    _multimap.insert(std::pair<int, int> (2, 4200));

    std::multimap<int , int> ::iterator itr;
    
    _multimap.erase(2);

    // erase from begining till 4th.
    _multimap.erase(_multimap.begin(), _multimap.find(4));
    std::cout << "KEY\tELEMENT\n";
    for (itr = _multimap.begin(); itr != _multimap.end(); ++itr)
        std::cout << itr->first << "\t" << itr->second << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    vector_test();
    deque_test();
    multimap_test();
    return (0);
}
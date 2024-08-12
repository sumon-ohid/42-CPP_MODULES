/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:34:57 by msumon            #+#    #+#             */
/*   Updated: 2024/08/12 10:45:36 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <map>

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

void map_test()
{
    std::cout << std::endl;
    std::cout << "*** MAP ***" << std::endl;
    std::map <int , int> _map;
    _map.insert(std::pair<int, int> (0, 42));
    _map.insert(std::pair<int, int> (4, 122));
    _map.insert(std::pair<int, int> (3, 142));
    _map.insert(std::pair<int, int> (5, 542));
    _map.insert(std::pair<int, int> (1, 1112));
    _map.insert(std::pair<int, int> (6, 432));
    _map.insert(std::pair<int, int> (2, 4200));

    std::map<int , int> ::iterator itr;
    
    _map.erase(2);

    // erase from begining till 4th.
    _map.erase(_map.begin(), _map.find(4));
    std::cout << "KEY\tELEMENT\n";
    for (itr = _map.begin(); itr != _map.end(); ++itr)
        std::cout << itr->first << "\t" << itr->second << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    vector_test();
    deque_test();
    map_test();
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:14:36 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 11:30:27 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
    std::cout << std::endl;
    std::cout << "*** Int test ***" << std::endl;
    int tab[] =
    {
        0, 1, 2, 3, 4
    };
    
    iter(tab, 5, print_T);
    std::cout << std::endl;

    std::cout << "*** float test ***" << std::endl;
    float flo[] =
    {
        10.0, 10.50, 42.00, 33.33, 4.24
    };
    
    iter(flo, 5, print_T);
    std::cout << std::endl;
    
    std::cout << "*** String test ***" << std::endl;
    std::string str[] =
    {
        "Hello", "World !", "Template", "is Fun!!"
    };
    
    iter(str, 4, print_T);
    std::cout << std::endl;
    
    std::cout << "*** Bool test ***" << std::endl;
    bool boo[] =
    {
        true, false, true, false
    };
    
    iter(boo, 4, print_T);
    std::cout << std::endl;
    return 0;
}

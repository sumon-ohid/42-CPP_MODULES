/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:46:53 by msumon            #+#    #+#             */
/*   Updated: 2024/07/04 11:09:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int g_var = 1;
int f(void)
{
    return (2);
}

namespace Foo
{
    int g_var = 3;
    int f(void)
    {
        return (4);
    }    
}

namespace Bar
{
    int g_val = 5;
    int f(void)
    {
        return (6);
    
    }
}

namespace Muf = Bar;

int main()
{
    std::cout << "Global Variable: " << g_var << std::endl;
    std::cout << "Global Function: " << f() << std::endl;
    std::cout << "Foo Namespace Variable: " << Foo::g_var << std::endl;
    std::cout << "Foo Namespace Function: " << Foo::f() << std::endl;
    std::cout << "Bar Namespace Variable: " << Bar::g_val << std::endl;
    std::cout << "Bar Namespace Function: " << Bar::f() << std::endl;
    std::cout << "Muf Namespace Variable: " << Muf::g_val << std::endl;
    std::cout << "Muf Namespace Function: " << Muf::f() << std::endl;
    std::cout << "Global Variable: " << ::g_var << std::endl;
    std::cout << "Global Function: " << ::f() << std::endl;
    return (0);
}
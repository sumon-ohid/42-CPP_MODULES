/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:09:58 by msumon            #+#    #+#             */
/*   Updated: 2024/07/04 14:59:27 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

Sample::Sample(int p, char q, float r):a(p),b(q),c(r)
{    
    std::cout << "Constructor called" << std::endl;

    std::cout << "a ->" << this->a << std::endl;
    std::cout << "b ->" << this->b << std::endl;
    std::cout << "c ->" << this->c << std::endl;
    
    this->bar(100);
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::bar(int var)
{
    std::cout << "This is inside bar()." << std::endl;
    std::cout << var << std::endl;
    std::cout << "Member function of the class." << std::endl;
    return;
}

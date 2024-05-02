/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:00:06 by msumon            #+#    #+#             */
/*   Updated: 2024/05/02 22:14:27 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int hello()
{
    std::cout << "Hello, Zohan!\n";
    return (10);
}

int main()
{
    int ret_hello = 0;
    std::cout << "Hello, World!\n";
    ret_hello = hello();
    std::cout << "Hello this is the return value of hello function " << ret_hello << "\n";
    return (0);
}

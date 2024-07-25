/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstrac_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:13:23 by msumon            #+#    #+#             */
/*   Updated: 2024/07/25 11:19:19 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Foo
{
    public:
        virtual void print() const = 0;
};

//abstract base class
class Bar : public Foo
{
    public:
    //pure virtual function
    //must re initiate the function.
        virtual void print() const
        {
            std::cout << "I am Bar class" << std::endl;
        }
};

int main()
{
    Bar h1;
    
    h1.print();
    return (0);
}
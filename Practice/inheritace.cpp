/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:34:02 by msumon            #+#    #+#             */
/*   Updated: 2024/07/22 13:49:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Base
{
    private:
        int a;
        int b;
    public:
        Base();
        Base(int x, int y);
        ~Base();

        void print();
};

Base::Base()
{
    a = 0;
    b = 0;
    std::cout << "Base Constructor" << std::endl;
}

Base::~Base()
{
    std::cout << "Base destructor" << std::endl;
}

Base::Base(int x, int y)
{
    a = x;
    b = y;
    std::cout << "Base param constructor" << std::endl;
}

void Base::print()
{
    std::cout << "a is : " << a << "\nb is : " << b << std::endl;
}

class Deprived : public Base
{
    private:
        int x;
    public:
        Deprived(int p, int q, int x);
        int getX();
};

Deprived::Deprived(int p, int q, int s) : Base(p, q)
{
    x = s;
}

int Deprived::getX()
{
    return (x);
}

int main()
{
    Deprived goo(10, 5, 42);
    goo.print();
    std::cout << goo.getX() << std::endl;
    return (0);
}
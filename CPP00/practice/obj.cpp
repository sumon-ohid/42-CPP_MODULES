/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:26:12 by msumon            #+#    #+#             */
/*   Updated: 2024/07/08 20:17:57 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Sample
{
    public:
        int foo;
        Sample()
        {
            std::cout << "Constructor called" << std::endl;
        }
        Sample(std::string name)
        {
            std::cout << "Hello " << name << std::endl;
        }
        ~Sample()
        {
            std::cout << "Destructor called" << std::endl;
        }
        void helloWorld(void);
        void privateFoo(void)
        {
            _privateFoo = 21;
            std::cout << "_privateFoo: " << _privateFoo << std::endl;
        }

    private:
        int _privateFoo;
};

void Sample::helloWorld(void)
{
    std::cout << "Hello World from Sample!" << std::endl;
}

int main(void)
{
    Sample instance;

    instance.helloWorld();
    instance.foo = 42;
    instance.privateFoo();
    std::cout << "foo: " << instance.foo << std::endl;
    return (0);
}
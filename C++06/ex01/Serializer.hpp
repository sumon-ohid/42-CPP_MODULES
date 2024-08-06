/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:09:47 by msumon            #+#    #+#             */
/*   Updated: 2024/08/06 21:11:32 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

struct Data
{
    std::string _string1;
    std::string _string2;
    int _nubmer1;
    int _nubmer2;
    char _char;
    bool _bool;
};

class Serializer
{   
    //private constructor to prevent creating instances of this class
    private:
        Serializer();
        Serializer(Serializer const &copy);
         ~Serializer();
        Serializer &operator=(Serializer const &copy);

    protected:

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

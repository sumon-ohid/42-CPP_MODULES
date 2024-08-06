/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:09:41 by msumon            #+#    #+#             */
/*   Updated: 2024/08/06 21:13:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data._string1 = "Hello";
    data._string2 = "World";
    data._nubmer1 = 42;
    data._nubmer2 = 21;
    data._char = 'c';
    data._bool = true;

    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "\033[32m**** Data in Serialized ****" << std::endl;
    std::cout << "String1: " << data._string1 << std::endl;
    std::cout << "String2: " << data._string2 << std::endl;
    std::cout << "Number1: " << data._nubmer1 << std::endl;
    std::cout << "Number2: " << data._nubmer2 << std::endl;
    std::cout << "Char: " << data._char << std::endl;
    std::cout << "Bool: " << data._bool << std::endl;
    std::cout << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "\033[34m**** Data in Deserialized **** " << std::endl;
    std::cout << "String1: " << deserialized->_string1 << std::endl;
    std::cout << "String2: " << deserialized->_string2 << std::endl;
    std::cout << "Number1: " << deserialized->_nubmer1 << std::endl;
    std::cout << "Number2: " << deserialized->_nubmer2 << std::endl;
    std::cout << "Char: " << deserialized->_char << std::endl;
    std::cout << "Bool: " << deserialized->_bool << std::endl;
    std::cout << "\033[0m" << std::endl;

    if (deserialized == &data)
        std::cout << "✅ ✅ Deserialization successful! ✅ ✅" << std::endl;
    else
        std::cout << "❌ ❌ Deserialization failed! ❌ ❌" << std::endl;

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:00:20 by msumon            #+#    #+#             */
/*   Updated: 2024/08/06 18:18:18 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    _input = "";
}

ScalarConverter::ScalarConverter(std::string input)
{
    _input = input;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{   
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    if (this != &copy)
    {
        _input = copy._input;
    }
    return *this;
}

int ScalarConverter::string_to_int(std::string input)
{
    int result = 0;
    int sign = 1;
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
    {
        if (input[i] == '-')
            sign = -1;
        i++;
    }
    for (; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
            throw std::invalid_argument("Invalid input: not a digit");
        result = result * 10 + (input[i] - '0');
    }
    return sign * result;
}

void ScalarConverter::convert(std::string input)
{   
    try 
    {
        int result = string_to_int(input);
        char result_char = static_cast<char>(result);
        if (result < 32 || result > 126)
            std::cerr << "char: " << "Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << result_char << "'" << std::endl;
    }
    catch (...)
    {
        std::cout << "char: impossible" << std::endl;
    }
    // char result_char = static_cast<char>(result);
    // double result_double = static_cast<double>(result);
    // float result_float = static_cast<float>(result);
    // std::cout << "char: " << "'" << result_char << "'" << std::endl;
    // std::cout << "float: " << result_float << std::endl;
    // std::cout << "double: " << result_double << std::endl;
}

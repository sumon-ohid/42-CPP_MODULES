/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:00:20 by msumon            #+#    #+#             */
/*   Updated: 2024/08/07 11:35:59 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

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
            throw std::invalid_argument("impossible");
        result = result * 10 + (input[i] - '0');
    }
    return sign * result;
}

void ScalarConverter::string_to_float(std::string input)
{
    if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
    {
        std::cout << "float: " << input << "f" << std::endl;
        return;
    }
    else
    {
        float f = static_cast<float>(string_to_int(input));
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void ScalarConverter::string_to_double(std::string input)
{
    if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
    {
        std::cout << "double: " << input << std::endl;
        return;
    }
    else
    {
        double d = static_cast<double>(string_to_int(input));
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
    try
    {
        char c = string_to_int(input);
        if (c >= 32 && c <= 126)
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            throw std::invalid_argument("Non displayable");
    }
    catch(const std::exception& e)
    {
        std::cerr << "char: " << e.what() << std::endl;
    }

    try
    {
        int i = string_to_int(input);
        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "int: " << e.what() << std::endl;
    }

    try 
    {
        string_to_float(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << "float: " << e.what() << std::endl;
    }

    try 
    {
        string_to_double(input);
    }
    catch(const std::exception& e) 
    {
        std::cerr << "double: " << e.what() << std::endl;
    }
}

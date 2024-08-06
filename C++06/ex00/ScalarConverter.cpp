/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:00:20 by msumon            #+#    #+#             */
/*   Updated: 2024/08/06 22:21:14 by msumon           ###   ########.fr       */
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

float ScalarConverter::string_to_float(std::string input)
{
    float result = 0;
    float sign = 1;
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
    {
        if (input[i] == '-')
            sign = -1;
        i++;
    }
    for (; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]) && input[i] != '.')
            throw std::invalid_argument(input + "f");
        if (input[i] == '.')
            break;
        result = result * 10 + (input[i] - '0');
    }
    float decimal = 0.1;
    for (++i; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
            throw std::invalid_argument(input + "f");
        result += (input[i] - '0') * decimal;
        decimal *= 0.1;
    }
    return sign * result;
}

double ScalarConverter::string_to_double(std::string input)
{
    double result = 0;
    double sign = 1;
    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
    {
        if (input[i] == '-')
            sign = -1;
        i++;
    }
    for (; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]) && input[i] != '.')
            throw std::invalid_argument(input);
        if (input[i] == '.')
            break;
        result = result * 10 + (input[i] - '0');
    }
    double decimal = 0.1;
    for (++i; i < input.length(); ++i)
    {
        if (!std::isdigit(input[i]))
            throw std::invalid_argument(input);
        result += (input[i] - '0') * decimal;
        decimal *= 0.1;
    }
    return sign * result;
}

void ScalarConverter::convert(std::string input)
{
    try {
        char c = string_to_int(input);
        if (c >= 32 && c <= 126)
            std::cout << "char: " << c << std::endl;
        else
            throw std::invalid_argument("Char: Non displayable");
    }
    catch(const std::exception& e) {
        std::cerr << "char: " << e.what() << std::endl;
    }

    try {
        int i = string_to_int(input);
        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "int: " << e.what() << std::endl;
    }

    try {
        float f = string_to_float(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "float: " << e.what() << std::endl;
    }

    try {
        double d = string_to_double(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "double: " << e.what() << std::endl;
    }
}

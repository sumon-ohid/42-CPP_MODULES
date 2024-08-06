/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:00:23 by msumon            #+#    #+#             */
/*   Updated: 2024/08/06 18:07:51 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
    private:
        std::string _input;
        ScalarConverter();

    protected:

    public:
        ScalarConverter(std::string input);
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &copy);
    
        void convert(std::string input);
        int string_to_int(std::string input);
        // void string_to_double(std::string input);
        // void string_to_float(std::string input);
};

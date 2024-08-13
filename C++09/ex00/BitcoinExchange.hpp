/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:08 by msumon            #+#    #+#             */
/*   Updated: 2024/08/13 18:09:02 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <climits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _bitcoin;

    public:
        BitcoinExchange();
        BitcoinExchange(std::map<std::string, float> bitcoin);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        bool date_validation(std::string date);
        bool value_validation(std::string value);
};

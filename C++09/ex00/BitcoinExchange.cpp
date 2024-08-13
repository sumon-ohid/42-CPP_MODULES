/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:11 by msumon            #+#    #+#             */
/*   Updated: 2024/08/13 18:09:18 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    _bitcoin.insert(std::pair<std::string, float>(NULL, 0.0));
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> bitcoin)
{
    _bitcoin = bitcoin;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    _bitcoin = copy._bitcoin;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        _bitcoin = copy._bitcoin;
    }
    return (*this);
}

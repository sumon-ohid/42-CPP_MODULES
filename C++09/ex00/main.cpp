/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:54 by msumon            #+#    #+#             */
/*   Updated: 2024/08/14 16:34:56 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

std::string input_content;
std::string data_content;

int error(std::string message)
{
    std::cerr << message << std::endl;
    return (-1);
}

int main(int ac, char **av)
{
    int line_count = 0;
    std::multimap<std::string, float> bitcoin;
    if (ac != 2)
        return error("Error: could not open file.");
    if (file_is_valid(av[1], input_content) && file_is_valid("data.csv", data_content))
    {
        std::string *input = data_extractor(input_content, line_count);
        if (headline_checker(input[0]) == false)
        {
            delete [] input;
            return error("Error: bad input => headline.");
        }
        std::string *input_values = get_values(input, line_count, 1);
        std::string *input_dates = get_dates(input, line_count, 1);
        std::string *data = data_extractor(data_content, line_count);
        std::string *data_values = get_values(data, line_count, 0);
        std::string *data_dates = get_dates(data, line_count, 0);
        make_multimap(data_dates, data_values, line_count, bitcoin);
        search_data(input_dates, input_values, bitcoin);
        delete [] input_dates;
        delete [] input_values;
        delete [] data_dates;
        delete [] data_values;
        delete [] input;
        delete [] data;
    }
    return 0;
}

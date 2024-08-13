/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:11:54 by msumon            #+#    #+#             */
/*   Updated: 2024/08/13 18:38:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <map>
#include <variant>

std::string input_content;
std::string data_content;

int error(std::string message)
{
    std::cerr << message << std::endl;
    return (-1);
}

bool file_is_valid(std::string filename, std::string &content)
{
    std::ifstream btcfile(filename.c_str());
    
    if (!btcfile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (false);
    }
    else
    {
        std::stringstream buffer;
        buffer << btcfile.rdbuf();
        content = buffer.str();
    }
    btcfile.close();
    return (true);
}

void remove_spaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

bool headline_checker(std::string headline)
{
    if (headline != "date|value")
        return false;
    return true;
}

std::string* data_extractor(const std::string& str, int &line_count)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            line_count++;
        i++;
    }
    
    std::stringstream ss(str);
    std::string line;
    std::string* ret = new std::string[line_count];
    i = 0;
    while (std::getline(ss, line))
    {
        remove_spaces(line);
        ret[i] = line;
        i++;
    }
    return ret;
}

std::string *get_dates(std::string *data, int size)
{
    std::string *dates = new std::string[size];
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            break;
        dates[i] = data[i + 1].substr(0, 10);
        if (dates[i].size() != 10)
        {
            dates[i] = "Error:";
            continue;
        }
        else if (dates[i][4] != '-' || dates[i][7] != '-')
        {
            dates[i] = "Error:";
            continue;
        }
    }
    return dates;
}

std::string *get_values(std::string *data, int size)
{
    std::string *values = new std::string[size];
    for (int i = 0; i < size; ++i)
    {
        unsigned int j = 0;
        if (i == size - 1)
            break;
        while (j < data[i + 1].size() && data[i + 1][j] != '|')
            j++;
        if (j == data[i + 1].size() || data[i + 1][j] != '|')
        {
            values[i] = "Error: bad input => " + data[i + 1];
            continue;
        }
        values[i] = data[i + 1].substr(j + 1);
        float f = atof(values[i].c_str());
        if (f < 0)
        {
            values[i] = "Error: not a positive number.";
            continue;
        }
        else if (f > 2147483647.0)
        {
            values[i] = "Error: too large a number.";
            continue;
        }
    }
    return values;
}

void make_map(std::string *dates, std::string *values, int size, std::map<std::string, float> &bitcoin)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "OK " << dates[i] << " => " << values[i] << std::endl;
        bitcoin.insert(std::pair<std::string, float>(dates[i], atof(values[i].c_str())));
    }
}

int main(int ac, char **av)
{
    int line_count = 0;
    std::map<std::string, float> bitcoin;
    if (ac != 2)
        return error("Error: could not open file.");
    if (file_is_valid(av[1], input_content) && file_is_valid("data.csv", data_content))
    {
        std::string *data = data_extractor(input_content, line_count);
        if (headline_checker(data[0]) == false)
            return error("Error: invalid data.");
        std::string *values = get_values(data, line_count);
        std::string *dates = get_dates(data, line_count);
        make_map(dates, values, line_count, bitcoin);
    
        delete [] dates;
        delete [] values;
        delete [] data;
    }
    return 0;
}

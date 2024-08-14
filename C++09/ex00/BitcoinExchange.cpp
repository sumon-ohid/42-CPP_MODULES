/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:11 by msumon            #+#    #+#             */
/*   Updated: 2024/08/14 11:30:17 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

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

std::string *get_dates(std::string *data, int size, int flag)
{
    std::string *dates = new std::string[size];
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            break;
        dates[i] = data[i + 1].substr(0, 10);
        if (flag == 1)
        {
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
    }
    return dates;
}

std::string *get_values(std::string *data, int size, int flag)
{
    std::string *values = new std::string[size];
    for (int i = 0; i < size; ++i)
    {
        unsigned int j = 0;
        if (i == size - 1)
            break;
        if (flag == 1)
        {
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
        else 
        {
            while (j < data[i + 1].size() && data[i + 1][j] != ',')
                j++;
            if (j > 1)
                values[i] = data[i + 1].substr(j + 1);
        }
    }
    return values;
}

void make_multimap(std::string *dates, std::string *values, int size, std::multimap<std::string, float> &bitcoin)
{
    for (int i = 0; i < size; i++)
    {
        bitcoin.insert(std::make_pair(dates[i], atof(values[i].c_str())));
    }
}

void search_data(std::string *dates, std::string *values, int size, std::multimap<std::string, float> &bitcoin)
{
    std::multimap<std::string, float>::iterator it;
    for (it = bitcoin.begin(); it != bitcoin.end(); it++)
    {
        for (int i = 0; i < size; i++)
        {
            if (it->first == dates[i])
            {
                float f = atof(values[i].c_str());
                values[i] = std::tostring(f * it->second);
                std::cout << dates[i] << " " << std::fixed << std::setprecision(2) << values[i] << std::endl;
            }
        }
    }
}

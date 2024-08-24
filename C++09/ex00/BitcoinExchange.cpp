/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:11 by msumon            #+#    #+#             */
/*   Updated: 2024/08/24 08:41:48 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void remove_spaces(std::string *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i].erase(std::remove(data[i].begin(), data[i].end(), ' '), data[i].end());
    }
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
        if (content.empty())
        {
            std::cerr << "Error: file is empty." << std::endl;
            return (false);
        }
    }
    btcfile.close();
    return (true);
}

bool is_valid_number(std::string &str)
{
    if (find(str.begin() + 1, str.end(), ' ') != str.end())
        return false;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    bool hasDecimalPoint = false;
    bool hasDigits = false;
    size_t start = 0;

    if (str[0] == '+' || str[0] == '-')
        start = 1;
    for (size_t i = start; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
            hasDigits = true;
        else if (str[i] == '.')
        {
            hasDecimalPoint = true;
        }
        else
            return false;
    }
    return hasDigits || hasDecimalPoint;
}

bool headline_checker(std::string headline)
{
    if (headline != "date | value")
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
    line_count++;
    std::stringstream ss(str);
    std::string line;
    std::string* ret = new std::string[str.size() + 1];
    i = 0;
    while (std::getline(ss, line))
    {
        //remove_spaces(line);
        ret[i] = line;
        i++;
    }
    return ret;
}

bool is_valid_date(const std::string &date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    if (find(date.begin(), date.begin() + 10, ' ') != date.begin() + 10)
        return false;
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days_in_month[] = {31, (is_leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day <= days_in_month[month - 1];
}

std::string *get_dates(std::string *data, int size, int flag)
{
    std::string *dates = new std::string[size];
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            break;
        if (flag == 0 && !is_valid_date(data[i + 1].substr(0, 10)))
            i++;
        dates[i] = data[i + 1].substr(0, 10);
    }
    return dates;
}

std::string *get_values(std::string *data, int size, int flag)
{
    std::string *values = new std::string[size];
    remove_spaces(data, size);
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
                values[i] = "Error: bad input";
                continue;
            }
            if (j + 1 >= data[i + 1].size()) // Check if there is only a pipe after the date
            {
                values[i] = "Error: bad input";
                continue;
            }
            values[i] = data[i + 1].substr(j + 1);
            if (!is_valid_number(values[i]))
            {
                values[i] = "Error: bad input";
                continue;
            }
            double f = atof(values[i].c_str());
            if (f < 0)
            {
                values[i] = "Error: not a positive number.";
                continue;
            }
            else if (f > 1000)
            {
                values[i] = "Error: too large a number.";
                continue;
            }
        }
        else 
        {
            while (j < data[i + 1].size() && data[i + 1][j] != ',')
                j++;
            if (j == data[i + 1].size() || data[i + 1][j] != ',')
            {
                values[i] = "Error: bad input";
                continue;
            }
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

void search_data(std::string *dates, std::string *values, const std::multimap<std::string, float> &bitcoin, unsigned int size)
{
    for (unsigned int i = 0; i < size - 2; i++)
    {
        float value = std::atof(values[i].c_str());
        std::multimap<std::string, float>::const_iterator it = bitcoin.lower_bound(dates[i]);
        if (it == bitcoin.end() || it->first != dates[i])
        {
            if (it != bitcoin.begin())
            {
                --it;
            }
        }
        if (values[i] == "Error: not a positive number." || values[i] == "Error: too large a number.")
        {
            std::cerr << values[i] << std::endl;
            continue;
        }
        if (!is_valid_date(dates[i]))
        {
            std::cerr << "Error: bad input => " + dates[i] << std::endl;
            continue;
        }
        else if (values[i] == "Error: bad input")
        {
            std::cerr << values[i] << " => " << dates[i] << std::endl;
            continue;
        }
        else
        {
            float res = value * it->second;
            if (res > LONG_MAX || res < 0)
            {
                std::cerr << "Error: bad input => " << dates[i] << std::endl;
                continue;
            }
            else
                std::cout << dates[i] << " => " << values[i] << " = " << std::fixed << std::setprecision(2) << value * it->second << std::endl;
        }
    }
}

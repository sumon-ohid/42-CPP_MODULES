/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:53:00 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 15:40:19 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileWriter.hpp"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>

FileWriter::FileWriter()
{
}

FileWriter::FileWriter(std::string filename): filename(filename)
{
}

FileWriter::~FileWriter()
{
}

std::string FileWriter::ft_reader(std::string filename)
{
    std::string content;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: file not found" << std::endl;
        return "";
    }
    else
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        content = buffer.str(); //convert buffer to string
    }
    file.close();
    return content;
}

std::string FileWriter::ft_replace(std::string filename, std::string target, std::string source)
{
    std::string result;
    size_t pos = 0;
    size_t lastPos = 0;
    while ((pos = filename.find(target, pos)) != std::string::npos)
    {
        result += filename.substr(lastPos, pos - lastPos);
        result += source;
        pos += target.length(); 
        lastPos = pos;
    }
    result += filename.substr(lastPos);
    return result;
}

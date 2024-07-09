/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:50:27 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 15:12:26 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileWriter.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./filewriter [filename] [target string] [source string]" << std::endl;
        return 1;
    }
    
    FileWriter fileWriter;
    std::string filename = argv[1];
    std::string target = argv[2];
    std::string source = argv[3];
    std::string content = fileWriter.ft_reader(filename);
   
    std::ofstream newFile("newfile");
    if (!newFile.is_open())
    {
        std::cerr << "Error: file not found." << std::endl;
        return 1;
    }
    else
    {
        std::string replacedContent = fileWriter.ft_replace(content, target, source);
        newFile << replacedContent;
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:50:27 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 16:23:33 by msumon           ###   ########.fr       */
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
    
    std::string filename = argv[1];
    std::string target = argv[2];
    std::string source = argv[3];
    std::string content = ft_reader(filename);
    if (content.empty())
    {
        std::cerr << "Empty file." << std::endl;
        return 1;
    }
   
    std::ofstream newFile("newfile");
    if (!newFile.is_open())
    {
        std::cerr << "Error: file not found." << std::endl;
        return 1;
    }
    else
    {
        std::string replacedContent = ft_replace(content, target, source);
        newFile << replacedContent;
    }
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:52:47 by msumon            #+#    #+#             */
/*   Updated: 2024/07/09 13:48:49 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEWRITER_HPP
# define FILEWRITER_HPP

#include <iostream>
#include <string>

class FileWriter
{
    private:
        std::string filename;
    public:
        FileWriter();
        FileWriter(std::string filename);
        ~FileWriter();
        std::string ft_reader(std::string filename);
        std::string ft_replace(std::string filename, std::string target, std::string source);    
};

#endif
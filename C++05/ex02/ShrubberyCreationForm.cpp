/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:15:59 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 16:54:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm(_target, 145, 137)
{
    target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy)
{
    target = copy.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return (*this);
    this->target = copy.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream file(target + "_shrubbery");
    if (!file)
        return ;
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\*\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\*\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\*\\/\\/*/\\/*/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << " |---------|  " << std::endl;
    file << "  \\       /  " << std::endl;
    file << "   \\     /   " << std::endl;
    file << "    \\___/    " << std::endl;
    file.close();
}

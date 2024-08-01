/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:14:43 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 15:48:18 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(Intern &copy)
{
    if (this == &copy)
        return (copy);
    return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form, std::string target)
{   
    std::string forms[3] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};

    switch (form.compare(forms[0]))
    {
        case 0:
            return (new RobotomyRequestForm(target));
            break;
        case 1:
            return (new ShrubberyCreationForm(target));
            break;
        case 2:
            return (new PresidentialPardonForm(target));
            break;
        default:
            throw std::runtime_error("Invalid Form");
    }
    return (NULL);
}

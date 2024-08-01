/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 15:48:01 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat Shrub("Shrub", 1); 
    
    try 
    {
        {
            std::cout << "*** Shrubbery ***" << std::endl;
            ShrubberyCreationForm SForm("Home");
            Shrub.signForm(SForm);
            Shrub.executeForm(SForm);
            std::cout << std::endl;
        }
        {
            std::cout << "*** Robotomy ***" << std::endl;
            RobotomyRequestForm RForm("Home");
            Shrub.signForm(RForm);
            Shrub.executeForm(RForm);
            std::cout << std::endl;
        }
        {
            std::cout << "*** Presidential ***" << std::endl;
            PresidentialPardonForm PForm("Home");
            Shrub.signForm(PForm);
            Shrub.executeForm(PForm);
            std::cout << std::endl;
        }
        {
            std::cout << "*** Intern ***" << std::endl;
            Intern intern;
            AForm *form = intern.makeForm("ShrubberyCreationForm", "Intern");
            Shrub.signForm(*form);
            Shrub.executeForm(*form);
            std::cout << std::endl;
            delete form;
        }
        {
            std::cout << "*** Intern ***" << std::endl;
            Intern intern;
            AForm *form = intern.makeForm("Invalid", "Intern");
            Shrub.signForm(*form);
            Shrub.executeForm(*form);
            std::cout << std::endl;
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);   
}

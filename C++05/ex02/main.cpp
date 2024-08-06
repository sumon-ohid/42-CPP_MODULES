/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 17:04:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat Shrub("Shrub", 10);
    
    try 
    {
        {
            std::cout << "*** Shrubbery ***" << std::endl;
            ShrubberyCreationForm SForm("Home");
            Shrub.signForm(SForm);
            Shrub.executeForm(SForm);
            std::cout << std::endl;

            Shrub.signForm(SForm);
            std::cout << std::endl;
        }
        {
            std::cout << "*** Shrubbery ***" << std::endl;
            ShrubberyCreationForm SForm1("School");
            Shrub.signForm(SForm1);
            Shrub.executeForm(SForm1);
            std::cout << std::endl;
        }
        {
            std::cout << "*** Shrubbery ***" << std::endl;
            ShrubberyCreationForm SForm2("Office");
            Shrub.signForm(SForm2);
            Shrub.executeForm(SForm2);
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
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);   
}

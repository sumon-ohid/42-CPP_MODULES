/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:51:32 by msumon            #+#    #+#             */
/*   Updated: 2024/07/29 15:01:36 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
{
    grade = 0;
    std::cout << "✅✅ Constructor from Bureaucrate ✅✅" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name), grade(_grade)
{
    if (_grade < 1)
        Bureaucrat::GradeTooLowException();
    else if (_grade > 150)
        Bureaucrat::GradeTooHighException();
    std::cout << "➡️➡️ Constructor with Parameter ⬅️⬅️" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &copy)
{
    if (this == &copy)
        return (copy);
    grade = copy.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "🗑️🗑️ Destructor from Bureaucrat 🗑️🗑️" << std::endl;
}

void Bureaucrat::GradeTooHighException()
{
    throw std::runtime_error("Grade is too High (range 1 - 150)");
}

void Bureaucrat::GradeTooLowException()
{
    throw std::runtime_error("Grade is too Low (range 1 - 150)");
}

std::string Bureaucrat::getName()
{
    return (name);
}

int Bureaucrat::getGrade()
{
    return (grade);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &copy)
{
    os << copy.getGrade();
    os << copy.getName();
    return (os);
}

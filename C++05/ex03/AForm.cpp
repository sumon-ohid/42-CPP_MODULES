/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:21:04 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 12:07:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : signed_AForm(false), grade_sign(0), grade_exe(0)
{
    signed_AForm = false;
}

AForm::AForm(const std::string _name, int _grade_sign, int _grade_exe) : name(_name), signed_AForm(false), grade_sign(_grade_sign), grade_exe(_grade_exe)
{
    Bureaucrat bureaucrat;
    if (_grade_sign < 1 || _grade_exe < 1)
        bureaucrat.GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exe > 150)
        bureaucrat.GradeTooLowException();
}

AForm &AForm::operator=(AForm &copy)
{
    if (this == &copy)
        return (copy);
    signed_AForm = copy.signed_AForm;
    return (*this);
}

AForm::AForm(AForm &copy) : name(copy.name), signed_AForm(copy.signed_AForm), grade_sign(copy.grade_sign), grade_exe(copy.grade_exe)
{
    *this = copy;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > grade_sign)
        throw std::runtime_error("Grade is too Low to sign the AForm");
}

std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeSign() const
{
    return grade_sign;
}

int AForm::getGradeExe() const
{
    return grade_exe;
}

bool AForm::getSigned() const
{
    return signed_AForm;
}

AForm::~AForm()
{
    //std::cout << "🗑️🗑️ Destructor from AForm 🗑️🗑️" << std::endl;
}

std::ostream &operator<<(std::ostream &os, AForm &copy)
{
    os << copy.getName() << std::endl;
    os << copy.getSigned() << std::endl;
    os << copy.getGradeSign() << std::endl;
    os << copy.getGradeExe() << std::endl;
    return (os);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:21:04 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 15:13:40 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : signed_form(false), grade_sign(0), grade_exe(0)
{
    signed_form = false;
}

Form::Form(const std::string _name, int _grade_sign, int _grade_exe) : name(_name), signed_form(false), grade_sign(_grade_sign), grade_exe(_grade_exe)
{
    if (_grade_sign < 1 || _grade_exe < 1)
        Form::GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exe > 150)
        Form::GradeTooLowException();
}

Form &Form::operator=(Form &copy)
{
    if (this == &copy)
        return (copy);
    signed_form = copy.signed_form;
    return (*this);
}

Form::Form(Form &copy) : name(copy.name), signed_form(copy.signed_form), grade_sign(copy.grade_sign), grade_exe(copy.grade_exe)
{
    *this = copy;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (signed_form)
    {
        std::cerr << "Already Signed" << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > grade_sign)
        throw std::runtime_error("Grade is too Low to sign the Form");
    signed_form = true;
}

std::string Form::getName()
{
    return name;
}

int Form::getGradeSign()
{
    return grade_sign;
}

int Form::getGradeExe()
{
    return grade_exe;
}

bool Form::getSigned()
{
    return signed_form;
}

void Form::GradeTooHighException()
{
    throw std::runtime_error("Grade is too High (range 1 - 150)");
}

void Form::GradeTooLowException()
{
    throw std::runtime_error("Grade is too Low (range 1 - 150)");
}

Form::~Form()
{
    //std::cout << "🗑️🗑️ Destructor from Form 🗑️🗑️" << std::endl;
}

std::ostream &operator<<(std::ostream &os, Form &copy)
{
    os << copy.getName() << std::endl;
    os << copy.getSigned() << std::endl;
    os << copy.getGradeSign() << std::endl;
    os << copy.getGradeExe() << std::endl;
    return (os);
}
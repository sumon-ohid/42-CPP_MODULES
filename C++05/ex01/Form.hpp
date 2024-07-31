/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:21:07 by msumon            #+#    #+#             */
/*   Updated: 2024/07/31 18:29:34 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool signed_form;
        const int grade_sign;
        const int grade_exe;
    
    protected:

    public:
        Form();
        Form(const std::string _name, int _grade_sign, int _grade_exe);
        Form(Form &copy);
        Form &operator=(Form &copy);
        ~Form();

        void beSigned(Bureaucrat &bureaucrat);
        std::string getName();
        bool getSigned();
        int getGradeSign();
        int getGradeExe();
        void GradeTooHighException();
        void GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, Form &copy);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:49:17 by msumon            #+#    #+#             */
/*   Updated: 2024/07/31 18:26:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <string>

class Bureaucrat : public Form
{
    private:
        const std::string name;
        int grade;
    
    protected:
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string _name, int _grade);
        Bureaucrat(Bureaucrat &copy);
        Bureaucrat &operator=(Bureaucrat &copy);
        ~Bureaucrat();

        void GradeTooHighException();
        void GradeTooLowException();
        std::string getName();
        int getGrade();
        void increment();
        void decrement();
        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &copy);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:49:17 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 14:54:22 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <string>

class Bureaucrat
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
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &form);

};

std::ostream &operator<<(std::ostream &os, Bureaucrat &copy);
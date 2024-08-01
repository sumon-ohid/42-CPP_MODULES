/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:49:17 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 14:19:54 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
        int getGrade();
        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &copy);

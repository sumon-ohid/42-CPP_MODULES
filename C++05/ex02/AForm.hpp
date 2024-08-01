/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:21:07 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 11:59:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

// Forward declaration
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool signed_AForm;
        const int grade_sign;
        const int grade_exe;
    
    protected:

    public:
        AForm();
        AForm(const std::string _name, int _grade_sign, int _grade_exe);
        AForm(AForm &copy);
        AForm &operator=(AForm &copy);
        virtual ~AForm();

        void beSigned(Bureaucrat &bureaucrat);
        std::string getName() const;
        bool getSigned() const; 
        int getGradeSign() const;
        int getGradeExe() const;
        void GradeTooHighException();
        void GradeTooLowException();

        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm &copy);

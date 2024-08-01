/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:15:51 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 11:36:31 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    protected:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string _name);
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

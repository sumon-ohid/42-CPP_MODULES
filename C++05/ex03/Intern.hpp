/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:12:34 by msumon            #+#    #+#             */
/*   Updated: 2024/08/01 12:24:43 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
    private:

    protected:
    
    public:
        Intern();
        Intern(Intern &copy);
        Intern &operator=(Intern &copy);
        ~Intern();
        AForm *makeForm(std::string form, std::string target);
};

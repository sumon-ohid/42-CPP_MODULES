/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:14:37 by msumon            #+#    #+#             */
/*   Updated: 2024/07/31 18:34:57 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat bureaucrat("Sami", 10);
    Form form("Nebula", 150, 150);

    try
    {
        bureaucrat.decrement();
        form.beSigned(bureaucrat);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    bureaucrat.signForm(form);

    return (0);
}

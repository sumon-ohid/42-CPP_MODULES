/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:45:31 by msumon            #+#    #+#             */
/*   Updated: 2024/07/05 09:58:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"

int main()
{
    CatClass cat1;

    cat1.print_cat();

    CatClass cat2("Neeeeew");

    cat2.print_cat();

    CatClass cat3("Meeeeeeeeeeeew", "Red", "Everything");

    cat3.print_cat();
    return (0);    
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:07:41 by msumon            #+#    #+#             */
/*   Updated: 2024/07/04 14:52:57 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class Sample
{
    public:
    
        int foo;
        int a;
        char b;
        float c;
        
        Sample(int a, char b, float c);
        ~Sample(void);
        
        void bar(int var);
};

#endif
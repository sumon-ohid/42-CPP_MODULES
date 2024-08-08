/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:02:21 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 12:29:26 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int n;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();

        Array &operator=(const Array &other);

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        unsigned int size() const;
};

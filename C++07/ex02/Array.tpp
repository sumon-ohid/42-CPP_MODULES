/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:08:58 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 14:54:39 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    elements = new T[0];    
    n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
    elements = new T[n];
}

template <typename T>
Array<T>::Array(Array &copy) : n(copy.n)
{
    elements = new T[n];
    for (unsigned int i = 0; i < n; ++i)
    {
        elements[i] = copy.elements[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array &copy)
{
    if (this != &copy)
    {
        delete[] elements;
        n = copy.n;
        elements = new T[n];
        for (unsigned int i = 0; i < n; ++i)
        {
            elements[i] = copy.elements[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= n)
    {
        throw std::runtime_error ("Index out of range");
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return n;
}

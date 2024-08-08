/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:08:58 by msumon            #+#    #+#             */
/*   Updated: 2024/08/08 12:11:51 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    elements = NULL;
    n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : n(n)
{
    elements = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other) : n(other.n)
{
    elements = new T[n];
    for (unsigned int i = 0; i < n; ++i)
    {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] elements;
        n = other.n;
        elements = new T[n];
        for (unsigned int i = 0; i < n; ++i)
        {
            elements[i] = other.elements[i];
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
const T &Array<T>::operator[](unsigned int index) const 
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

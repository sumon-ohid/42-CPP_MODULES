/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:19:44 by msumon            #+#    #+#             */
/*   Updated: 2024/08/13 09:29:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    protected:

    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const T &value) : std::stack<T>(value) {}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        virtual ~MutantStack() {}

        MutantStack &operator=(const MutantStack &copy)
        {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return (*this);
        }

        // define iterator
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }

        iterator end()
        {
            return (std::stack<T>::c.end());
        }
};

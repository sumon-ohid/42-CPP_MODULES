/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:08:41 by msumon            #+#    #+#             */
/*   Updated: 2024/08/15 12:13:55 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

int evaluateRPN(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            if (find(token.begin(), token.end(), '.') != token.end())
                throw std::runtime_error("Error");
            stack.push(std::atoi(token.c_str()));
        }
        else 
        {
            if (stack.size() < 2)
            {
                throw std::runtime_error("Error");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0) {
                    throw std::runtime_error("Error: Division by zero");
                }
                stack.push(a / b);
            }
            else
                throw std::runtime_error("Error: Unknown operator: " + token);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        int result = evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:08:41 by msumon            #+#    #+#             */
/*   Updated: 2024/08/15 16:39:51 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

// Initialize a stack to store operands.
// Split the input string by spaces to get individual tokens.
// Iterate through each token:
// If the token is a number, push it onto the stack.
// If the token is an operator (+, -, *, /), pop the required number of operands from the stack, perform the operation, and push the result back onto the stack.
// The final result should be the only element left in the stack.

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
            int num = std::atoi(token.c_str());
            if (num < 0 || num > 10)
                throw std::runtime_error("Error");
            stack.push(std::atoi(token.c_str()));
        }
        else 
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
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
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
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

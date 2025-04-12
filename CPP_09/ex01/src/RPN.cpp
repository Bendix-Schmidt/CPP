/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:58:04 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/11 18:58:05 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//methods
int RPN::performOperation(int a, int b, const std::string &op) const {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/")
	{
		if (b == 0) throw std::runtime_error("Division by zero");
			return (a / b);
	}
	throw std::runtime_error("Invalid operator");
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else if (isValidOperator(token))
		{
			if (stack.size() < 2) throw std::runtime_error("Invalid expression");
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(performOperation(a, b, token));
		}
		else
			throw std::runtime_error("Invalid token");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	int result = stack.top();
	stack.pop();
	return (result);
}

//helper
bool RPN::isValidOperator(const std::string &token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

//constructors and destructor
RPN::RPN()
{}

RPN::RPN(const RPN &oth) : stack(oth.stack)
{}

RPN &RPN::operator=(const RPN &oth)
{
	if (this != &oth)
	{
		stack = oth.stack;
	}
	return (*this);
}

RPN::~RPN()
{}
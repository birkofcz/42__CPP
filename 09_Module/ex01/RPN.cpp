/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:30:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 16:08:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* OCC */
RPN::RPN() : _expression("")
{
}

RPN::RPN(std::string expression) : _expression(expression)
{
}

RPN::RPN(const RPN& original)
{
	*this = original;
}

RPN& RPN::operator=(const RPN& src)
{
	if (this != &src)
	{
		this->_expression = src._expression;
		this->_stack = src._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

/* Methods */

std::string RPN::getExpression() const {return _expression;}

double RPN::myAtoi(std::string src)
{
	std::stringstream ss(src);
	double result;
	ss >> result;
	
	return result;
}

int RPN::calculate()
{
	std::string expression = getExpression();
	for (std::string::iterator it = expression.begin(); it != expression.end(); ++it)
	{
		char token = *it;
		if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%')
		{
			if (_stack.size() < 2)
			{
				std::cerr << RED "Error: Not enough values in stack" RES << std::endl;
				return 1;
			}
			double a = _stack.top();
			_stack.pop();
			double b = _stack.top();
			_stack.pop();
			if (token == '+')
				_stack.push(b + a);
			else if (token == '-')
				_stack.push(b - a);
			else if (token == '*')
				_stack.push(b * a);
			else if (token == '/')
				_stack.push(b / a);
			else if (token == '%')
				_stack.push(fmod(b, a));
		}
		else if (token == ' ')
			continue;
		else if (token >= '0' && token <= '9')
			_stack.push(myAtoi(std::string(1, token)));
		else
		{
			std::cerr << RED "Error: Invalid character" RES << std::endl;
			return 1;
		}
	}
	std::cout << GRE "Result: " RES << _stack.top() << std::endl;
	return 0;
}
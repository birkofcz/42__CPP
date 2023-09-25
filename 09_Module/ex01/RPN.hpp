/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:15:37 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 16:31:55 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <cmath>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define RES "\033[0m"

/* 
Container of choice here is STACK.
The RPN was designed to be used in stack-based electronic and computers.
 */
class RPN
{
	private:
		std::stack<float>	_stack;
		std::string			_expression;
		double				myAtoi(std::string src);

	public:
	/* OCC */
		RPN();
		RPN(std::string expression);
		RPN(const RPN& original);
		RPN& operator=(const RPN& src);
		~RPN();

		int	calculate();
		std::string getExpression() const;
};

/* 
RPN - Reverse Polish Notation

- https://en.wikipedia.org/wiki/Reverse_Polish_notation
- https://medium.com/@ainayat865/reverse-polish-notation-rpn-with-stack-4551a5f54ae0

RPN is a mathematical notation in which every operator follows all of its operands, in contrast to 
Polish notation, which puts the operator in the prefix position. It is also known as postfix notation 
and is parenthesis-free as long as operator arities are fixed.

It was designed to be used in stack-based electronic and computer logic circuits 
(e.g., using relays) such as those that would have been found in Turing's theoretical Automatic Computing Engine.
Compared to infix notation, RPN reduces the number of characters needed in memory to represent complex
operations, thus allowing instructions to be more easily stored inside the processor and increasing
the processing speed.

 */

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:07:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/17 17:08:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <exception>

#define GRE "\033[32m"
#define RED "\033[31m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define RES "\033[0m"

class Span
{
	private:
		std::set<int> _set;
		unsigned int _maxsize;

	public:

		void addNumber(int number);
		void addNumbers(std::set<int>::iterator iBegin, std::set<int>::iterator iEnd);

		int shortestSpan();
		int longestSpan();

		void printSet();
		int getSize();

		Span();
		Span(unsigned int N);
		Span(const Span& original);
		Span& operator=(const Span& src);
		~Span();
};

#endif
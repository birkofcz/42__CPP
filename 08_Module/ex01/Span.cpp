/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:12:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/19 11:44:03 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>

/* OCC */
Span::Span(){}

Span::Span(unsigned int N)
{
	_maxsize = N;
}

Span::Span(const Span& original)
{
	if (!original._set.empty())
	{
		for (std::set<int>::iterator i = original._set.begin(); i != original._set.end(); i++)
			_set.insert(*i);
	}
}

Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		_set.clear();
		for (std::set<int>::iterator i = src._set.begin(); i != src._set.end(); i++)
			_set.insert(*i);
	}
	return *this;
}

Span::~Span(){}

/* Methods */
void Span::addNumber(int number)
{
	if (_set.size() >= _maxsize)
		throw std::out_of_range("Error: set is full, cannot add more numbers");
	else
		_set.insert(number);
}

void Span::addNumbers(std::set<int>::iterator iBegin, std::set<int>::iterator iEnd)
{
	if (_set.size() >= _maxsize)
		throw std::out_of_range("Error: set is full, cannot add more numbers");
	_set.insert(iBegin, iEnd);
}

/* 
Shortest span si calculated by taking two adjacent numbers from the set and comparing them.
Which ever difference is smaller, it is saved as the shortest span.
 */
int Span::shortestSpan()
{
	if (_set.size() < 2)
		throw std::out_of_range("Error: there are not enough numbers");
	//we need two iterators to go through the set
	std::set<int>::iterator num = _set.begin();
	std::set<int>::iterator next_num = _set.begin();
	std::advance(next_num, 1); 				// next_num = num + 1 (first two numbers)

	int shortest_span = *next_num - *num;  // Initial difference for first two numbers

	/* this for loop is ommiting the first part of the syntax, 
	because we already initialized the iterators (and using them before the for loop) */
	for (; next_num != _set.end(); ++num, ++next_num)
	{
		int current_diff = *next_num - *num;
		if (current_diff < shortest_span)
			shortest_span = current_diff;
	}
	return shortest_span;
}

int Span::longestSpan()
{
	if (_set.size() < 2)
		throw std::out_of_range("Error: there is not enough numbers");
	//taking advantage of ordered set.....last one - first one....:)
	return (*_set.rbegin() - *_set.begin());
} 

void Span::printSet()
{
	std::set<int>::iterator i;
	for (i = _set.begin(); i != _set.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

int Span::getSize(){return _set.size();}
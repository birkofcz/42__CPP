/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:12:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/17 17:08:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

int	Span::shortestSpan()
{
	if (_set.size() < 2)
		throw std::out_of_range("Error: there is not enough numbers");
	//need a second number from an ordered set - to calculate shortest span
	//fotn that, I set iterator and than advamce it by one, sending it to the second number...
	std::set<int>::iterator second_num = _set.begin();
	std::advance(second_num, 1);
	//_set.insert(smallest);
	return (*second_num - *_set.begin());
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
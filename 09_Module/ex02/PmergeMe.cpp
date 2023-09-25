/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:15:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 17:51:06 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* OCC */
PmergeMe::PmergeMe()
{
}

/* 
The whole show will be run from the constructor.
 */
PmergeMe::PmergeMe(int ac, char **av)
{
	// 1. parsing the input, assuring there is no negative numbers
	for (int i = 0; i < ac; i++)
	{
		std::string number = av[i];
		if (MyAtoi(av[i]) < 0)
		{
			std::cout << RED << "Error: " << RES << "Invalid input." << std::endl;
			exit(1);
		}
		_lst_sequence.push_back(myAtoi(av[i]));
		_deq_sequence.push_back(myAtoi(av[i]));
	}
	// 2. printing the "Before: " part of the output
	std::cout << YEL "Before: " << RES;
	for (std::list<int>::iterator it = _lst_sequence.begin(); it != _lst_sequence.end(); ++it)
		std::cout << *it << " ";

	////continue here	

}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		_lst_sequence = src._lst_sequence;
		_deq_sequence = src._deq_sequence;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

/* Methods */
int PmergeMe::myAtoi(std::string src)
{
	std::stringstream ss(src);
	int result;
	ss >> result;
	
	return result;
}


std::list<int>	PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
	std::list<int> result;

	std::list<int>::iterator left_it = left.begin();
	std::list<int>::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) 
	{
		if (*left_it <= *right_it) 
		{
			result.push_back(*left_it);
			++left_it;
		} 
		else 
		{
			result.push_back(*right_it);
			++right_it;
		}
	}

	result.insert(result.end(), left_it, left.end());
	result.insert(result.end(), right_it, right.end());

	return result;
}

std::list<int> mergeSortList(const std::list<int>& lst) 
{
	if (lst.size() <= 1)
		return lst;

	std::list<int> left, right;
	std::list<int>::iterator middle = lst.begin();
	std::advance(middle, lst.size() / 2);

	// left.splice(left.begin(), const_cast<std::list<int>&>(lst), lst.begin(), middle);
	// right.splice(right.begin(), const_cast<std::list<int>&>(lst), middle, lst.end());
	// std::list<int> left(lst.begin(), std::next(lst.begin(), lst.size() / 2));
	// std::list<int> right(std::next(lst.begin(), lst.size() / 2), lst.end());

	std::list<int> left(lst.begin(), lst.begin() + lst.size() / 2);
	std::list<int> right(lst.begin() + lst.size() / 2, lst.end());

	left = mergeSortList(left);
	right = mergeSortList(right);

	return mergeList(left, right);
}

std::deque<int>	PmergeMe::mergeDeque(std::deque<int>& left, std::deque<int>& right)
{
	std::deque<int> result;

	std::deque<int>::iterator left_it = left.begin();
	std::deque<int>::iterator right_it = right.begin();

	while (left_it != left.end() && right_it != right.end())
	{
		if (*left_it <= *right_it)
		{
			result.push_back(*left_it);
			++left_it;
		}
		else
		{
			result.push_back(*right_it);
			++right_it;
		}
	}

	result.insert(result.end(), left_it, left.end());
	result.insert(result.end(), right_it, right.end());

	return result;
}

std::deque<int>	PmergeMe::mergeSortDeque(const std::deque<int>& deq) 
{
	if (deq.size() <= 1)
		return deq;

	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

	left = mergeSortDeque(left);
	right = mergeSortDeque(right);

	return mergeDeque(left, right);
}


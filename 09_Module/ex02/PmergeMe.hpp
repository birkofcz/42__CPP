/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:36:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 17:46:53 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <list>
# include <deque>
# include <algorithm>

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define RES "\033[0m"

/* 
Containers of choice here are LIST and DEQUE.
List is a container that supports constant time insertion 
and removal of elements from anywhere in the container.

Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends.
They provide a functionality similar to vectors, but with efficient insertion and deletion of elements also 
at the beginning of the sequence,
 */

class PmergeMe
{
	private:
		std::list<int>		_lst_sequence;
		std::deque<int>		_deq_sequence;

		int					myAtoi(std::string src);
		std::list<int> 		mergeList(std::list<int>& left, std::list<int>& right);
		std::deque<int>		mergeDeque(std::deque<int>& left, std::deque<int>& right);
		std::list<int>		mergeSortList(std::list<int>& _lst_sequence);
		std::deque<int>		mergeSortDeque(std::deque<int>& _deq_sequence);
	
	public:
	/* OCC */
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& original);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
};

#endif

/* 
Ford-johnson algorithm (merge-sort)
Merge-sort is a sorting algorithm that uses the idea of divide and conquer.
This algorithm splits the array in half, sorts each of those halves, and then merges them back together.
It uses recursion to perform the sort.

 */
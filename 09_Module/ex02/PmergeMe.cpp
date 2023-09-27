/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:15:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/27 13:11:15 by sbenes           ###   ########.fr       */
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
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber(av[i]) || myAtoi(av[i]) < 0)
			throw std::runtime_error(RED "Error: Invalid input." RES);
		_lst_sequence.push_back(myAtoi(av[i]));
		_deq_sequence.push_back(myAtoi(av[i]));
	}
	// 2. printing the "Before: " part of the output
	std::cout << std::endl << YEL "Input sequence: " RES << std::endl;
	std::cout << YEL "Before: " << RES;
	if (_lst_sequence.size() == 0)
		std::cout << "empty";
	else if (_lst_sequence.size() == 1)
		std::cout << _lst_sequence.front();
	else if (_lst_sequence.size() > 100)
	{
		std::list<int>::iterator it = _lst_sequence.begin();
		for (int i = 1; i < 10 && it != _lst_sequence.end(); ++i, ++it)
			std::cout << *it << " ";
		std::cout << "...";
	}
	else
		for (std::list<int>::iterator it = _lst_sequence.begin(); it != _lst_sequence.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
	// 3. sorting the list, timing the results on list and deque
	srand(time(NULL)); //seed random number generator - needed for time

	clock_t start_list = clock();
	_lst_sequence = mergeSortList(_lst_sequence);
	clock_t end_list = clock();
	double elapsed_list = double(end_list - start_list) / CLOCKS_PER_SEC;

	clock_t start_deque = clock();
	_deq_sequence = mergeSortDeque(_deq_sequence);
	clock_t end_deque = clock();
	double elapsed_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC;

	// 4. printing the "After: " part of the output
	std::cout << YEL "After: " << RES;
	if (_lst_sequence.size() == 0)
		std::cout << "empty";
	else if (_lst_sequence.size() == 1)
		std::cout << _lst_sequence.front();
	else if (_lst_sequence.size() > 100)
	{
		std::list<int>::iterator it = _lst_sequence.begin();
		for (int i = 1; i < 10 && it != _lst_sequence.end(); ++i, ++it)
			std::cout << *it << " ";
		std::cout << "..." << std::endl;
	}
	else
		for (std::list<int>::iterator it = _lst_sequence.begin(); it != _lst_sequence.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

	// 5. printing the time results. Setting precision to 6 decimal places, to get time in seconds.
	std::cout << std::endl << YEL "Time for processing the sequence: " RES << std::endl;
	std::cout << YEL << "List of size  " << _lst_sequence.size() << ": " << RES << std::fixed << std::setprecision(6) << elapsed_list << " seconds." << std::endl;
	std::cout << YEL << "Deque of size " << _deq_sequence.size() << ": " RES << std::fixed << std::setprecision(6) << elapsed_deque << " seconds." << std::endl;
	std::cout << std::endl;
	//some auto test if the list and deque are both sorted
	std::cout << YEL "isSorted(): " RES << std::endl;
	std::cout << YEL << "List: " << RES;
	if (isSorted(_lst_sequence.begin(), _lst_sequence.end()))
		std::cout << GRE "Sorted." RES << std::endl;
	else
		std::cout << RED "Not sorted." RES << std::endl;
	std::cout << YEL << "Deque: " << RES;
	if (isSorted(_deq_sequence.begin(), _deq_sequence.end()))
		std::cout << GRE "Sorted." RES << std::endl;
	else
		std::cout << RED "Not sorted." RES << std::endl;
	std::cout << std::endl;
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

bool PmergeMe::isNumber(const std::string& str) 
{
	for (std::string::size_type i = 0; i < str.size(); i++) 
	{
		if (i == 0 && str[i] == '-') 
			continue ;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

int PmergeMe::myAtoi(std::string src)
{
	std::stringstream ss(src);
	int result;
	ss >> result;
	
	return result;
}

/* 
Function to merge two sorted lists into one larger sorted list.
 */
std::list<int>	PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
	std::list<int> result;

	// Iterators for the left and right lists
	std::list<int>::iterator left_it = left.begin();
	std::list<int>::iterator right_it = right.begin();
	
	// Iterates through both lists and compares the values
	// Pushes the smaller value to the result list
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
	// Inserts the remaining values from the left and right lists
	// Because the while loop only runs until one of the lists is empty, 
	//the other list might have some values left over
	result.insert(result.end(), left_it, left.end());
	result.insert(result.end(), right_it, right.end());

	return result;
}

/* 
Function to sort a list using merge-sort. It splits the list into two halves,
recursively calls mergeSortList on the two halves, and then merges the two sorted halves.
 */
std::list<int> PmergeMe::mergeSortList(std::list<int>& lst) 
{
	if (lst.size() <= 1)
		return lst;

	std::list<int> left, right;
	// Splits the list into two halves using "mid" iterator advanced to the middle
	//That is because list does not support random access iterator
	std::list<int>::iterator mid = lst.begin();
	std::advance(mid, lst.size() / 2);

	// Assigns the values from the beginning to the middle to the left list
	// Assigns the values from the middle to the end to the right list
	left.assign(lst.begin(), mid);
	right.assign(mid, lst.end());

	// Recursively calls mergeSortList on the left and right lists
	// until they are broken down into lists of size 1
	left = mergeSortList(left);
	right = mergeSortList(right);

	// Merges the left and right lists back together- sorts them
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

std::deque<int> PmergeMe::mergeSortDeque(std::deque<int>& deq) 
{
	if (deq.size() <= 1)
		return deq;

	std::deque<int> left, right;
	// Deque supports random access iterator, so you can use direct arithmetic
	std::deque<int>::iterator mid = deq.begin() + deq.size() / 2;

	left.assign(deq.begin(), mid);
	right.assign(mid, deq.end());

	left = mergeSortDeque(left);
	right = mergeSortDeque(right);

	return mergeDeque(left, right);
}


/* 

Ilustration for Ford-Johnson algorithm on a list of 5 elements:

1.Initialization:
We pass our list to the mergeSortList function. Initially, our list looks like this:

8 -> 3 -> 7 -> 5 -> 2

2.Check Size of the List:
Inside mergeSortList, we first check if the size of the list is 1 or smaller. 
If it is, we simply return the list. For our example, the size is 5, so we proceed.

3.Splitting the List into Two Halves:
We create two empty lists: left and right. We then determine the midpoint of our 
list. The mid iterator will point to the middle of the list. Since our list size 
is 5, mid will point to 5, effectively splitting the list into two halves:

left:  8 -> 3
right: 7 -> 5 -> 2

4. Recursive Calls:
Now, we recursively call mergeSortList for the left and right lists:

First Recursion (left):
4.1 The list is 8 -> 3.
4.2 It gets split into:
	left: 8
	right: 3

4.3 These are further split until they each contain a single element.
4.4. Now, mergeList is called to merge these two lists (8 and 3). After merging, 
we get the sorted list 3 -> 8.

Second Recursion (right):
4.1 The list is 7 -> 5 -> 2.
4.2 It gets split into:
	left: 7
	right: 5 -> 2
4.3 The right list is further split and sorted to become 2 -> 5.
4.4. Finally, mergeList is called to merge 7 and the sorted list 2 -> 5, 
resulting in 2 -> 5 -> 7.

5. Merging the Two Sorted Halves:
Now that both the left list (3 -> 8) and the right list (2 -> 5 -> 7) are sorted, 
we need to merge them together. We call the mergeList function again:

Merging Process:
5.1 We create an empty result list.
5.2 Using iterators left_it and right_it, we iterate through the left and right lists.
5.3 At each step, we compare the elements pointed by these iterators and push the 
smaller one to the result list.
5.4 We keep doing this until we reach the end of one of the lists.
5.5 Finally, we add any remaining elements from the non-empty list to result.
After merging, our result list becomes:

2 -> 3 -> 5 -> 7 -> 8

6. Returning the Sorted List:
We return the result list, which is now a sorted version of our original list.

For the deque, the process is the same, except for the fact that we can use direct arithmetic
to determine the midpoint of the list, because deque supports random access iterator.
 */
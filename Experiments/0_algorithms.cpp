/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_algorithms.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:08:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/16 17:35:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

# define GRE "\033[32m"
# define RED "\033[31m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

/* 
////  What are Algorithms?

An algorithm is a step-by-step procedure or formula for solving a problem. Think of it like a recipe: to cook a particular dish, you follow a series of steps in a specific order. In computer science, algorithms operate on data and produce a desired output.

//// C++ Standard Library's Algorithms

The C++ standard library provides a set of built-in algorithms which are mainly defined in the header <algorithm>. These algorithms operate on sequences, such as arrays or containers from the standard library (e.g., std::vector, std::list).

Here's a quick overview of some categories and commonly used algorithms:

Sorting Algorithms:
sort(begin, end): Sorts the elements in a range.
partial_sort(begin, middle, end): Sorts the first N elements.
nth_element(begin, nth, end): Partially sorts the range such that the nth element is in its sorted position.

Searching Algorithms:
find(begin, end, value): Finds a value in a range.
binary_search(begin, end, value): Searches for a value in a sorted range using binary search.
lower_bound(begin, end, value): Finds the first position where a value could be inserted to keep the range sorted.
upper_bound(begin, end, value): Finds the last position where a value could be inserted to keep the range sorted.

Permutation Algorithms:
next_permutation(begin, end): Transforms the range into the next permutation.
prev_permutation(begin, end): Transforms the range into the previous permutation.

Miscellaneous Algorithms:
swap(a, b): Swaps the values of a and b.
replace(begin, end, old_value, new_value): Replaces occurrences of old_value with new_value.
remove(begin, end, value): Removes all occurrences of a value from a range.
unique(begin, end): Removes consecutive duplicate values.

Numeric Algorithms (defined in <numeric>):
accumulate(begin, end, init): Computes the sum of a range, initialized with an initial value.
inner_product(begin1, end1, begin2, init): Computes the dot product of two sequences.
partial_sum(begin, end, result): Computes the partial sum of a sequence.
 */


//tamplate of vector printing function - takes vector of any datatype
template <typename T>
void	printVector(std::vector<T>& vec)
{
	typename std::vector<T>::iterator i; //must be declared like this....typename...

	for (i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

int main()
{

	std::cout << GRE "\nExamples of algorithms in C++: " RES << std::endl;
	std::vector<int> vec;

	srand(static_cast<unsigned>(time(NULL))); // random number generator seed
	
	//generating a vector of 20ints, randomly generated
	for (int i = 0; i < 50; i++)
		vec.push_back(rand() % 100);
	
	//printing the vector
	std::cout << "\nvector<int> vec of 20 randomly chosen integers: " << std::endl; 
	printVector(vec);

	//doing magic with vec:
	std::sort(vec.begin(), vec.end());
	std::cout << "\nstd::sort(vec.begin(), vec.end()): " << std::endl;
	printVector(vec);

	







	
	
	
	return 0;

}
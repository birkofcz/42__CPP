/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:12 by sbenes            #+#    #+#             */
/*   Updated: 2023/10/01 11:24:30 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

/* 
Example of an for_each algorithm
 */

void displayInt(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	std::vector<int> v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	//for_each takes a function as a parameter and applies it to each element of the container
	for_each(v.begin(), v.end(), displayInt);

	//another useful algorithm is find. It returns an iterator to the element if found, 
	//or the end iterator if not found	
	std::vector<int>::iterator it = find(v.begin(), v.end(), 2);
	if (it != v.end())
		std::cout << "found: " << *it << std::endl;
	else
		std::cout << "not found" << std::endl;

	//another useful algorithm is count. It returns the number of occurences of a value in a container
	int count = std::count(v.begin(), v.end(), 2);
	std::cout << "count: " << count << std::endl;

	//another useful algorithm is sort. It sorts the container
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), displayInt);

	//another useful algorithm is reverse. It reverses the container
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), displayInt);

	//another useful algorithm is max_element. It returns an iterator to the max element
	std::vector<int>::iterator max = max_element(v.begin(), v.end());
	std::cout << "max: " << *max << std::endl;

	//another useful algorithm is min_element. It returns an iterator to the min element
	std::vector<int>::iterator min = min_element(v.begin(), v.end());
	std::cout << "min: " << *min << std::endl;
/* 
	//another useful algorithm is accumulate. It returns the sum of all elements in the container
	//it takes a third parameter, which is the initial value of the sum.
	int sum = accumulate(v.begin(), v.end(), 0);
	std::cout << "sum: " << sum << std::endl;

	//another useful algorithm is remove. It removes all occurences of a value from the container
	//it doesn't resize the container
	remove(v.begin(), v.end(), 2);
	for_each(v.begin(), v.end(), displayInt);

	//another useful algorithm is remove_if. It removes all elements that satisfy the predicate
	//it doesn't resize the container
	//in this case, we remove all elements that are equal to 1
	//the predicate is a lambda function. That is a function that is defined in place
	//the syntax is: [capture list](parameters){body}
	remove_if(v.begin(), v.end(), [](int i){return i == 1;});

	//another useful algorithm is transform. It applies a function to each element of the container
	//and stores the result in another container
	//in this case, we apply the function to square each element
	//the third parameter is the output iterator
	std::vector<int> v2;
	transform(v.begin(), v.end(), back_inserter(v2), [](int i){return i * i;});
	for_each(v2.begin(), v2.end(), displayInt);

	//another useful algorithm is replace. It replaces all occurences of a value with another value
	//in this case, we replace all occurences of 4 with 0
	replace(v2.begin(), v2.end(), 4, 0);
	for_each(v2.begin(), v2.end(), displayInt); */
	

	return (0);
}
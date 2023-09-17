/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/17 14:53:33 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <ctime>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		srand(time(NULL)); // Random number generator seed
		int num_to_find = std::atoi(av[1]); // Convert string to int

		/* Containers */
		std::vector<int> vec;
		std::list<int> lst;
		std::deque<int> deq;

		/* Filling the containers with random numbers using .push_back() method.
		for lst and deque, .push_front() is available
		lst is a doubly linked list, so it is not possible to use [] operator to access the element.
		*/
		for (int i = 0; i < 10; i++)
		{
			vec.push_back(rand() % 25);
			lst.push_back(rand() % 25);
			deq.push_back(rand() % 25);
		}

		/* ITERATOR is a pointer to the element in the container, it works just as clasic int i = 0; i < 10; i++,
		but it is more universal. We can make iterator for any container, not just for vector, list or deque.
		We can also use iterator to get the value of the element, just like with pointer (*i). */
		std::vector<int>::iterator vi;
		std::list<int>::iterator li;
		std::deque<int>::iterator di;

		/* iTERATORS used  to print the values of the containers, setting position to begin at for loop, 
		loopin till iterator != container end */
		std::cout << GRE "\nVector: " RES << std::endl;
		for (vi = vec.begin(); vi != vec.end(); vi++)
			std::cout << *vi << " ";
		std::cout << std::endl;

		std::cout << GRE "\nList: " RES << std::endl;
		for (li = lst.begin(); li != lst.end(); li++)
			std::cout << *li << " ";
		std::cout << std::endl;

		std::cout << GRE "\nDeque: " RES << std::endl;
		for (di = deq.begin(); di != deq.end(); di++)
			std::cout << *di << " ";
		std::cout << std::endl;

		/* We are using our function easyfind to find the value in the container*/
		std::cout << GRE "\nFinding value " << num_to_find << " in vector: " RES << std::endl;
		try{std::cout << easyfind(vec, num_to_find) << std::endl;}
		catch(const std::exception& e){std::cerr << RED "Value not found" RES << std::endl;}
		
		std::cout << GRE "\nFinding value " << num_to_find << " in list: " RES << std::endl;
		try{std::cout << easyfind(lst, num_to_find) << std::endl;}
		catch(const std::exception& e){std::cerr << RED "Value not found" RES << std::endl;}

		std::cout << GRE "\nFinding value " << num_to_find << " in deque: " RES << std::endl;
		try{std::cout << easyfind(deq, num_to_find) << std::endl;}
		catch(const std::exception& e){std::cerr << RED "Value not found" RES << std::endl;}
	}
	else
		return (std::cerr << RED "Wrong number of arguments" RES << std::endl, 1);
	return 0;
}

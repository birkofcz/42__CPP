/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/18 15:30:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
void printStack(std::stack<T> original)
{
	std::deque<T> tmp;
	while (!original.empty())
	{
		tmp.push_front(original.top());
		original.pop();
	}
	std::cout << std::endl;
	while (!tmp.empty())
	{
		std::cout << *tmp.begin() << " ";
		original.push(*tmp.begin());
		tmp.erase(tmp.begin());
	}
}

int main()
{
	std::cout << "\n------------------------------------------------------------" << std::endl;
	std::cout << GRE "\n   [[[ MUTANTSTACK TEST]]]   " RES << std::endl;
	std::cout << YEL "\nCreating a MutantStack<int> mstack ..." RES << std::endl;
	MutantStack<int> mstack;
	
	std::cout << YEL "mstack.push(5) ... mstack.push(17) ..." RES << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << "mstack.size(): "<< mstack.size() << std::endl;
	std::cout << "mstack.pop()" << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): "<< mstack.size() << std::endl;

	std::cout << YEL "mstack.push(3)..mstack.push(5)..mstack.push(737)..mstack.push(0) ..." RES << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << YEL "\nMutantStack<int> iterator i ... iterating THE STACK!: " RES << std::endl;
	MutantStack<int>::iterator i;
	for (i = mstack.begin(); i != mstack.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
/* 	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	} */
	std::cout << YEL "\nstd::stack<int> s(mstack) created..." RES << std::endl;
	std::stack<int> s(mstack);
	std::cout << YEL "Printing the stack<int> s with helper test function: " RES;
	printStack(s);	
	std::cout << "\n\n------------------------------------------------------------\n" << std::endl;

	return 0;
}	

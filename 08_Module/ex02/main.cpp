/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/18 16:49:35 by sbenes           ###   ########.fr       */
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
	std::cout << GRE "\n[[[ MutantStack TEST]]]   " RES << std::endl;
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

	std::cout << YEL "\nMutantStack<int>::iterator i ... iterating THE STACK!: " RES << std::endl;
	MutantStack<int>::iterator i;
	for (i = mstack.begin(); i != mstack.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	MutantStack<char> mstack2;
	std::cout << YEL "\nCreating a MutantStack<char> mstack2 ..." RES << std::endl;
	std::cout << YEL "mstack2.push('a')..mstack2.push('b')..mstack2.push('c')..mstack2.push('d') ..." RES << std::endl;
	mstack2.push('a');
	mstack2.push('b');
	mstack2.push('c');
	mstack2.push('d');
	std::cout << "mstack2.top(): " << mstack2.top() << std::endl;
	std::cout << "mstack2.size(): "<< mstack2.size() << std::endl;
	std::cout << "mstack2.pop()" << std::endl;
	mstack2.pop();
	std::cout << "mstack2.size(): "<< mstack2.size() << std::endl;
	std::cout << "mstack2.top(): " << mstack2.top() << std::endl;
	mstack2.push('e');
	std::cout << "mstack2.push('e')" << std::endl;
	std::cout << YEL "\nMutantStack<char>::iterator it ... iterating THE STACK!: " RES << std::endl;
	MutantStack<char>::iterator it;
	for (it = mstack2.begin(); it != mstack2.end(); it++)
		std::cout << *it << " ";
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
	std::cout << std::endl;
	s.pop();
	std::cout << "\ns.pop()"<< std::endl;
	printStack(s);
	std::cout << "\ns.size(): "<< s.size() << std::endl;

	std::cout << YEL "\nstd::stack<char> s2 = mstack2 created" RES << std::endl;
	std::stack<char> s2;
	s2 = mstack2;
	std::cout << YEL "Printing the stack<char> s2 with helper test function: " RES;
	printStack(s2);
	std::cout << std::endl;
	s2.push('f');
	std::cout << "\ns2.push('f')"<< std::endl;
	printStack(s2);
	std::cout << "\ns2.size(): "<< s2.size() << std::endl;
	std::cout << std::endl;

	std::cout << "\n\n------------------------------------------------------------\n" << std::endl;

	return 0;
}	

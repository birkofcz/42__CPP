/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:11 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/18 16:37:44 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <deque>
#include <stack>


#define GRE "\033[32m"
#define RED "\033[31m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define RES "\033[0m"

/* 
std::stack doesnt have iterators, so you need add them. You can simply inherit from 
stack class with template for data type. 
 */
template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
	MutantStack(){};
	MutantStack(const MutantStack& original){*this = original;}
	MutantStack& operator=(const MutantStack& src){(void)src; return *this;}
	~MutantStack(){};
	/* defining iterator type - it will be used in begin() and end() methods. 
	container_type is a type of container used in stack class (it is deque by default).
	and iterator is a type of iterator used in deque. */
	typedef typename std::stack<T>::container_type::iterator	iterator;
	/* begin() and end() methods return iterator to the beginning and end of the stack. 
	c is a container of stack class - and it is data member of stack class. */
	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}
};

#endif

//protoype of std::stack:
// template < class T, class Container = deque<T> > class stack;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:11 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/18 14:34:35 by sbenes           ###   ########.fr       */
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

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
	MutantStack(){};
	MutantStack(const MutantStack& original){*this = original;}
	MutantStack& operator=(const MutantStack& src){(void)src; return *this;}
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator	iterator;
	iterator begin(){return this->c.begin();}
	iterator end(){return this->c.end();}
};

#endif

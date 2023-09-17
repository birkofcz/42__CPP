/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:47:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/17 14:46:33 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

#define GRE "\033[32m"
#define RED "\033[31m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define RES "\033[0m"

template <typename T>
int easyfind(T& container, int value)
{
	typename T::iterator i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw std::exception();
	return (*i);
}

#endif

//Containers
//https://cplusplus.com/reference/stl/
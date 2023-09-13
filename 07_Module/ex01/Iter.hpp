/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:40:03 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/13 17:13:45 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <iomanip>

/* Colors */
# define GRE "\033[32m"
# define RED "\033[31m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

/* Templates */

template <typename T>
void	iter(T* array, int len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void 	add_a(T& array_element)
{
	//std::cout << std::fixed << std::setprecision(1);
	std::cout << array_element << "a" << std::endl;
}

#endif

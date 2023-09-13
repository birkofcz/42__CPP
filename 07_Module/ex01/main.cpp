/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/13 17:08:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


int main()
{
	int		arr_int[5] = {1, 2, 3, 4, 5};
	float	arr_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	arr_char[5] = {'a', 'b', 'c', 'd', 'e'};


	std::cout << GRE << "int array:" << RES << std::endl;
	iter(arr_int, 5, add_a);
	std::cout << GRE << "float array:" << RES << std::endl;
	iter(arr_float, 5, add_a);
	std::cout << GRE << "char array:" << RES << std::endl;
	iter(arr_char, 5, add_a);
	
	return (0);
}
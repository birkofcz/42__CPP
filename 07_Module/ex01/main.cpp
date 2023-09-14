/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/14 16:26:53 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


int main()
{
	int			arr_int[5] = {1, 2, 3, 4, 5};
	float		arr_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char		arr_char[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string	arr_string[5] = {"one-", "two-", "three-", "four-", "five-"};


	std::cout << GRE << "\nint array:" << RES << std::endl;
	iter(arr_int, 5, add_a);
	std::cout << GRE << "\nfloat array:" << RES << std::endl;
	iter(arr_float, 5, add_a);
	std::cout << GRE << "\nchar array:" << RES << std::endl;
	iter(arr_char, 5, add_a);
	std::cout << GRE << "\nstring array:" << RES << std::endl;
	iter(arr_string, 5, add_a);
	
	std::endl(std::cout);
	return (0);
}
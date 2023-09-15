/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/15 11:04:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <ctime>
#include <cstdlib>
#include <iomanip>	
#include <sstream>

int main()
{

	//seed for random numbers and precision for float
	srand(static_cast<unsigned>(time(NULL)));
	std::cout << std::fixed << std::setprecision(1);

	int			arr_int[5];
	float		arr_float[5];
	char		arr_char[5];
	std::string	arr_string[5];

	for (int i = 0; i < 5; i++)
	{
		arr_int[i] = rand() % 50;
		arr_float[i] = static_cast<float>(rand() % 50);
		arr_char[i] = static_cast<char>(rand() % 50 + 65);
		std::stringstream ss;  //convert int to string using stringstream.
		ss << i;
		arr_string[i] = "string" + ss.str() + "-";
	}


	std::cout << GRE << "\nint array:" << RES << std::endl;
	iter(arr_int, 5, printWithAppendedA);
	std::cout << GRE << "\nfloat array:" << RES << std::endl;
	iter(arr_float, 5, printWithAppendedA);
	std::cout << GRE << "\nchar array:" << RES << std::endl;
	iter(arr_char, 5, printWithAppendedA);
	std::cout << GRE << "\nstring array:" << RES << std::endl;
	iter(arr_string, 5, printWithAppendedA);
	
	std::endl(std::cout);
	return (0);
}
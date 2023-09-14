/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/14 16:27:21 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>

int main()
{
	//seed for random numbers and precision for float
	srand(static_cast<unsigned>(time(NULL)));
	std::cout << std::fixed << std::setprecision(1);

	std::cout << YEL << "\nDefault constructor test:" << RES << std::endl;
	Array<int>		arr_int0;
	printArray(arr_int0);

	std::cout << YEL << "\nConstructor with parameter test:" << RES << std::endl;
	std::cout << GRE << "Array of int: Array<int> arr_int(10)" << RES << std::endl;
	Array<int>		arr_int(10);
	for (int i = 0; i < arr_int.size(); i++)
		arr_int[i] = rand() % 50;
	printArray(arr_int);

	std::cout << GRE << "\nArray of float: Array<float> arr_float(10)" << RES << std::endl;
	Array<float>	arr_float(10);
	for (int i = 0; i < arr_float.size(); i++)
		arr_float[i] = static_cast<float>(rand() % 50);
	printArray(arr_float);

	std::cout << GRE << "\nArray of char: Array<char> arr_char(10)" << RES << std::endl;
	Array<char>		arr_char(10);
	for (int i = 0; i < arr_char.size(); i++)
		arr_char[i] = static_cast<char>(rand() % 50 + 65);
	printArray(arr_char);

	std::cout << GRE << "\nArray of string: Array<std::string> arr_string(10)" << RES << std::endl;
	Array<std::string>	arr_string(10);
	for (int i = 0; i < arr_string.size(); i++)
	{
		std::stringstream ss;
		ss << i;
		arr_string[i] = "string" + ss.str();
	}
	printArray(arr_string);
	

	std::cout << YEL << "\nCopy constructor test: Array<int> arr_int2(arr_int)" << RES << std::endl;
	Array<int>		arr_int2(arr_int);
	for (int i = 0; i < arr_int2.size(); i++)
		if (arr_int2[i] != arr_int[i])
			return (std::cout << RED << "Arrays don't match!" << RES << std::endl, 1);
	std::cout << GRE << "Arrays match!" << RES << std::endl;

	std::cout << YEL << "\nAssignment operator test: Array<int> arr_int3 = arr_int" << RES << std::endl;
	Array<int>		arr_int3 = arr_int;
	for (int i = 0; i < arr_int3.size(); i++)
		if (arr_int3[i] != arr_int[i])
			return (std::cout << RED << "Arrays don't match!" << RES << std::endl, 1);
	std::cout << GRE << "Arrays match!" << RES << std::endl;

	std::cout << YEL << "\nOut of range test:" << RES << std::endl;
	try
	{
		std::cout << "Valid index test on int array (arr_int[5]): " << arr_int[5] << std::endl;
		std::cout << "Invalid index test on int array (arr_int[11]): " << arr_int3[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RES << '\n';
	}
	std::endl(std::cout);

	

		
	
	return (0);
}

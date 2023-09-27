/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:33:55 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/27 14:30:16 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstring>


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << RED << "Error: No input." << RES << std::endl;
		return (1);
	}
	if (std::string(av[1]) == "-test")
	{
		try
		{
			std::cout << YEL << "Running tests..." << RES << std::endl;
			std::cout << std::endl;
			std::cout << GRE << "\nTest 1: 1000 numbers." << RES << std::endl;
			char **test1 = new char*[1002];
			test1[0] = av[0];	
			for (int i = 1; i < 1002; i++)
			{
				std::stringstream ss;
				ss << rand() % 3000;
				std::string str = ss.str();
				test1[i] = new char[str.length() + 1];
				strcpy(test1[i], str.c_str());
			}
			PmergeMe pm = PmergeMe(1002, test1);

			std::cout << GRE << "Test 2: 10000 numbers." << RES << std::endl;
			char **test2 = new char*[10002];
			test2[0] = av[0];
			for (int i = 1; i < 10002; i++)
			{
				std::stringstream ss;
				ss << rand() % 30000;
				std::string str = ss.str();
				test2[i] = new char[str.length() + 1];
				strcpy(test2[i], str.c_str());
			}
			PmergeMe pm2 = PmergeMe(10002, test2);
			std::cout << GRE << "Test 3: 100000 numbers." << RES << std::endl;
			char **test3 = new char*[100002];
			test3[0] = av[0];
			for (int i = 1; i < 100002; i++)
			{
				std::stringstream ss;
				ss << rand() % 300000;
				std::string str = ss.str();
				test3[i] = new char[str.length() + 1];
				strcpy(test3[i], str.c_str());
			}
			PmergeMe pm3 = PmergeMe(100002, test3);
			//free 
			for (int i = 1; i < 1002; i++)
				delete [] test1[i];
			delete [] test1;
			for (int i = 1; i < 10002; i++)
				delete [] test2[i];
			delete [] test2;
			for (int i = 1; i < 100002; i++)
				delete [] test3[i];
			delete [] test3;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
		return 0;

	}
	else
	{
		try
		{
			PmergeMe pm = PmergeMe(ac, av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	return 0;
}

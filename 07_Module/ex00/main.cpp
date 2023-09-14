/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/14 16:27:06 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"
#include <cstdlib>
#include <iomanip>
#include <typeinfo>

int	identify(char *str)
{
	std::string s(str);
	if (s == "char")
		return CHAR;
	else if (s == "int")
		return INT;
	else if (s == "float")
		return FLOAT;
	else if (s == "double")
		return DOUBLE;
	else
		return INVALID;
}

int main(int ac, char** av)
{
	if (ac == 4)
	{
		int type = identify(av[1]);
		std::cout << std::endl;
		switch (type)
		{
			case CHAR:
			{
				std::cout << "type identified: " << GRE << "char" << RES << std::endl;
				char a = av[2][0];
				char b = av[3][0];
				std::cout << "a = " << a << " [" << typeid(a).name() << "]"<< ", b = " << b << " [" << typeid(b).name() << "]"<< std::endl;
				std::cout << "calling ::swap(a, b)" << std::endl;
				::swap(a, b);
				std::cout << "a = " << a << ", b = " << b << std::endl;
				std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
				std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
				break;
			}
			case INT:
			{
				std::cout << "type identified: " << GRE << "int" << RES << std::endl;
				int a = std::atoi(av[2]);
				int b = std::atoi(av[3]);
				std::cout << "a = " << a << " [" << typeid(a).name() << "]"<< ", b = " << b << " [" << typeid(b).name() << "]"<< std::endl;
				::swap(a, b);
				std::cout << "calling ::swap(a, b)" << std::endl;
				std::cout << "a = " << a << ", b = " << b << std::endl;
				std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
				std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
				break;
			}
			case FLOAT:
			{
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "type identified: " << GRE << "float" << RES << std::endl;
				float a = std::atof(av[2]);
				float b = std::atof(av[3]);
				std::cout << "a = " << a << " [" << typeid(a).name() << "]"<< ", b = " << b << " [" << typeid(b).name() << "]"<< std::endl;
				::swap(a, b);
				std::cout << "calling ::swap(a, b)" << std::endl;
				std::cout << "a = " << a << ", b = " << b << std::endl;
				std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
				std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
				break;
			}
			case DOUBLE:
			{
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "type identified: " << GRE << "double" << RES << std::endl;
				double a = std::atof(av[2]);
				double b = std::atof(av[3]);
				std::cout << "a = " << a << " [" << typeid(a).name() << "]"<< ", b = " << b << " [" << typeid(b).name() << "]"<< std::endl;
				::swap(a, b);
				std::cout << "calling ::swap(a, b)" << std::endl;
				std::cout << "a = " << a << ", b = " << b << std::endl;
				std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
				std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
				break;
			}
			default:
				std::cerr << "Invalid type" << std::endl;
				break;
		}
		std::cout << std::endl;
	}
	else 
		return (std::cerr << "Wrong number of arguments" << std::endl, 1);
	return 0;
}
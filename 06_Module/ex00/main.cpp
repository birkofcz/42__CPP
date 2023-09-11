/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/10 12:01:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char** av)
{
	if (ac == 2)
	{
		try
		{
			ScalarConverter::convert(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}
	else if (ac == 3 && std::string(av[2]) == "-checker")
	{
		try
		{
			ScalarConverter::Checker(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}
	else
		return (std::cerr << RED << "Wrong number of arguments or invalid optional argument" << RES << std::endl, 1);
	return 0;
}


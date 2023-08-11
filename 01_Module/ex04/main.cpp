/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:49:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 17:12:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

void	ft_testprint(std::string infile, std::string find, std::string replace_with, std::string outfile)
{
	std::cout << "infile: " << infile << std::endl;
	std::cout << "find: " << find << std::endl;
	std::cout << "replace_with: " << replace_with << std::endl;
	std::cout << "outfile: " << outfile << std::endl;
}

void	ft_replacer(char **av)
{
	std::string	infile = 		av[1];
	std::string find = 			av[2];
	std::string	replace_with =	av[3];
	std::string	outfile =		infile + ".replace";

	ft_testprint(infile, find, replace_with, outfile);

	std::ifstream text(infile);
	if (text.is_open())
	{

	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: Bad arguments" << std::endl;
		std::cerr << "run ./replacer <filename> <string_to_find> <str_to_replace_with>" << std::endl;
		return 1;
	}
	else
	{
		ft_replacer(av);
	}
	return 0;
}
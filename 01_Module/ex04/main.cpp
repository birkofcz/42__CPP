/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:49:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 10:42:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

void	ft_testprint(std::string infile, std::string find, std::string replace_with, std::string outfile)
{
	std::cout << std::endl;
	std::cout << "|| infile: " << infile << " ||" << std::endl;
	std::cout << "|| string to find: " << find << " ||" << std::endl;
	std::cout << "|| replacement string: " << replace_with << " ||" << std::endl;
	std::cout << "|| outfile: " << outfile << " ||" << std::endl;
	std::cout << std::endl;
}

void	ft_replacer(char **av)
{
	std::string	infile = 		av[1];
	std::string find = 			av[2];
	std::string	replace_with =	av[3];
	std::string	outfile =		infile + ".replace";

	ft_testprint(infile, find, replace_with, outfile);

	size_t pos = 0;
	std::ifstream text(infile.c_str());
	if (text.is_open())
	{
		std::string buffer;
		std::getline(text, buffer, '\0');
		if (buffer.empty())
		{
			std::cerr << RED << "Error: File is empty\n" << RES << std::endl;
			return ;
		}
		while ((pos = buffer.find(find, pos)) != std::string::npos) 
		{
			buffer.erase(pos, find.length()); // Erase the found target string
			buffer.insert(pos, replace_with); // Insert the replacement string
			pos += replace_with.length(); // Move the position forward to avoid an infinite loop
		}
		std::ofstream edited(outfile.c_str());
		edited << buffer;
		text.close();
		edited.close();
		std::cout << GRE << "File successfully edited\n" << RES << std::endl;
	}
	else
		std::cerr << RED << "Error: Can't open file\n" << RES << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << RED << "Error: Bad arguments" << RES << std::endl;
		std::cerr << YEL << "run ./replacer <filename> <string_to_find> <str_to_replace_with>" << RES << std::endl;
		return 1;
	}
	else
		ft_replacer(av);
	return 0;
}
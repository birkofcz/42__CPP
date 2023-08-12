/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:49:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/12 15:47:27 by sbenes           ###   ########.fr       */
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

	size_t pos = 0;
	std::ifstream text(infile);
	if (text.is_open())
	{
		std::string buffer;
		std::getline(text, buffer, '\0');
		while ((pos = buffer.find(find, pos)) != std::string::npos) 
		{
			buffer.erase(pos, find.length()); // Erase the found target string
			buffer.insert(pos, replace_with); // Insert the replacement string
			pos += replace_with.length(); // Move the position forward to avoid an infinite loop
		}
		//buffer = ft_strreplace(buffer, find, replace_with);
		std::ofstream edited(outfile);
		edited << buffer;
		text.close();
		edited.close();
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
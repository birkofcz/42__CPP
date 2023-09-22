/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:52:53 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/22 16:25:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./ex00 [filepath]" << std::endl;
		return 1;
	}
	
	BTC database("data.csv");

	database.printDatabase(-1,"2010");

	/* Comparison part of the program */
	std::string						filepath = av[1];
	std::vector<std::string>		split;
	std::ifstream					infile(filepath.c_str()); //.c_str() is needed to be std98 compliant
	std::string						line;

	while (std::getline(infile, line))
	{
		split = CppSplit(line, '|');
		if (std::find(split[0].begin(), split[0].end(), '-') != split[0].end()) // to check if the date is in the right format
		{
			std::map<std::string, float> data = database.getDatabase();
			std::map<std::string, float>::iterator it = data.find(split[0]);
			if (it != data.end())
			{
				float value;
				std::stringstream ss(split[1]);
				ss >> value;
				std::cout << split[0] << " | " << split[1] << " => " << value * it->second << std::endl;
			}
		}
	}
	
	
	return 0;
}
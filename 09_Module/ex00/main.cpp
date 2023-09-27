/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:52:53 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/27 14:47:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static bool testDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::vector<std::string>	split;
	split = CppSplit(date, '-');
	if (split.size() != 3)
		return false;
	if (split[0].size() != 4 || split[1].size() != 2 || split[2].size() != 2)
		return false;
	if (split[1] > "12" || split[1] < "01")
		return false;
	if (split[2] > "31" || split[2] < "01")
		return false;
	return true;
}

static bool testNumber(std::string number)
{
	std::stringstream ss(number);
	float num;
	ss >> num;
	if (num > 0 && num < 1000)
		return true;
	return false;
}



int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./btc <filepath>" << std::endl;
		return 1;
	}
	
	BTC database("data.csv");

	//database.printDatabase(-1, "2011");
	std::cout << std::endl;

	/* Comparison part of the program */
	std::string						filepath = av[1];
	std::vector<std::string>		split;
	std::ifstream					infile(filepath.c_str()); //.c_str() is needed to be std98 compliant
	std::string						line;

	if (!infile)
	{
		std::cout << "Error: cannot open file" << std::endl;
		return 1;
	}
	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: empty file" << std::endl;
		return 1;
	}
	while (std::getline(infile, line))
	{
		//test if the line has | in it
		//SKIP THE LINE IF IT DOEST START	WITH A DATE
		if (line.find("20") != 0)
			continue;
		if (line.find("|") != std::string::npos)
		{
			split = CppSplit(line, '|');
			//test if date - split[0] - is in the right format
			split[0] = trimSpace(split[0]);
			split[1] = trimSpace(split[1]);
			if (testDate(split[0]))
			{
				//test if the date is in the database
				//if (database.getDatabase().find(split[0]) != database.getDatabase().end())
				std::string key = split[0];
				if (database.getDatabase().count(split[0]) > 0)
				{
					//test if the value is in the right format
					if (testNumber(split[1]))
					{
						float value1 = CppStof(split[1]);
						float value2 = database.getDatabase().find(split[0])->second;
						std::cout << split[0] << " | " << value1 << " => " << value1 * value2 << std::endl;
					}
					else
						std::cout << "Error: number too large or negative => " << line << std::endl;
				}
				else
				{
					//date not in database - TAKING VALUE FROM THE LAST KNOWN DATE
					std::map<std::string, float> localBase = database.getDatabase();
					std::map<std::string, float>::const_iterator	it;
					std::string										lastDate;
					float											lastValue;

					for (it = localBase.begin(); it != localBase.end(); ++it)
					{
						if (it->first < split[0])
						{
							lastDate = it->first;
							lastValue = it->second;
						}
						else
							break;
					}
					//std::cout << "nearest date: " << lastDate << std::endl; //testprint for nearest date found
					if (testNumber(split[1]))
					{
						float value1 = CppStof(split[1]);
						std::cout << split[0] << " not in database, using: " << lastDate << " | " << value1 << " => " << value1 * lastValue << std::endl;
					}
					else
						std::cout << "Error: bad input format => " << line << std::endl;
				}
								
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;

		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
	return 0;
}

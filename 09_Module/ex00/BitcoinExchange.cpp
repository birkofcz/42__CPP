/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:18:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/22 15:31:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* OCC */

BTC::BTC() : _Nrecords(0)
{
}

/* 
The program has to operate with a database of dates and prices. It is a good idea 
to create this database in the constructor of the class (filepath as a parameter).
The container of choice is std::map. The key is a string representing the date
and the value is a float representing the price.
 */
BTC::BTC(std::string filepath) : _Nrecords(0)
{
	std::vector<std::string>		split;
	std::ifstream					infile(filepath.c_str()); //.c_str() is needed to be std98 compliant
	std::string						line;

	while (std::getline(infile, line))
	{
		split = CppSplit(line, ',');
		if (std::find(split[0].begin(), split[0].end(), '-') != split[0].end()) // to check if the date is in the right format
		{
			this->_database[split[0]] = CppStof(split[1]);
			this->_Nrecords++;
		}

	}
	infile.close(); //this will be done automatically, but for the sake of clarity ...
}

BTC::BTC(const BTC& original)
{
	*this = original;
}

BTC& BTC::operator=(const BTC& src)
{
	if (this != &src)
	{
		this->_database = src.getDatabase();
		this->_Nrecords = src.getNrecords();
	}
	return (*this);
}

BTC::~BTC(){}

/* Methods */

std::map<std::string, float>	BTC::getDatabase() const {return (this->_database);}

int	BTC::getNrecords() const {return (this->_Nrecords);}

/* 
Function to print the parsed database - you can specify the number of lines to print to be 
able to print only the first few lines of the database as sample. You can also specify the year
.

 */
void	BTC::printDatabase(int lines, const std::string& year) const
{
	//function optionally takes number of lines to print and year to filter.
	int		i = 0;
	std::map<std::string, float>::const_iterator	it;

	for (it = this->_database.begin(); it != this->_database.end(); ++it)
	{
		if (year != "" && it->first.substr(0, 4) != year)
			continue;
		std::cout << it->first << " | " << it->second << std::endl;
		i++;
		if (lines != -1 && i >= lines)
			break;
	}
		std::cout << std::endl;
		std::cout << "Lines printed: " << i << std::endl;
		std::cout << "Records in database: " << this->_Nrecords << std::endl;
}

/* Functions */

/* 
Good old split...
 */
std::vector<std::string>	CppSplit(std::string str, char delimiter)
{
	std::vector<std::string>	result;
	std::stringstream			ss(str);
	std::string					token;

	while (std::getline(ss, token, delimiter))
		result.push_back(token);
	return (result);
}

/* 
Converting function string->float using the sstream.
The standard library function stof is not available in C++98

 */
float	CppStof(std::string str)
{
	std::stringstream	ss(str);
	float				result;

	ss >> result;
	return (result);
}


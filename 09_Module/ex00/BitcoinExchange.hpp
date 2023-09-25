/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:11:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 16:30:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <vector>
# include <map>
# include <algorithm>
# include <fstream>
# include <stdexcept>

/* 
Container of choice here is MAP.
Map is a sorted associative container that contains key-value pairs with unique keys.
This makes it great for storing data that needs to be associated with other data.

I will also use VECTOR for storing the data from the file.
 */

class BTC
{
	private:
		std::map<std::string, float>	_database;
		int _Nrecords;

		bool 						testDate(std::string date);
		bool 						testNumber(std::string number);

	public:
		BTC();
		BTC(std::string records);
		BTC(const BTC& original);
		BTC & operator=(const BTC& src);
		~BTC();

		/* getters */
		std::map<std::string, float>	getDatabase() const;
		int								getNrecords() const;

		/* methods */
		void	printDatabase(int lines = -1, const std::string& year = "") const;
		void	compareData(std::string filepath);

};

std::vector<std::string>	CppSplit(std::string str, char delimiter);
std::string					CppTrim(std::string str);
float						CppStof(std::string str);
std::string					trimSpace(std::string& src);
#endif
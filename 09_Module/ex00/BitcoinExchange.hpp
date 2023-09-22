/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:11:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/22 14:21:30 by sbenes           ###   ########.fr       */
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

class BTC
{
	private:
		std::map<std::string, float>	_database;
		int _Nrecords;

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
		void							printDatabase(int lines = -1, const std::string& year = "") const;

};

std::vector<std::string>		CppSplit(std::string str, char delimiter);
std::string						CppTrim(std::string str);
float							CppStof(std::string str);
#endif
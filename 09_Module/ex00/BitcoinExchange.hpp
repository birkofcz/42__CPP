/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:11:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/21 14:20:00 by sbenes           ###   ########.fr       */
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
		std::map<std::string, float> _data;

	public:
		BTC();
		BTC(BTC const & src);
		BTC & operator=(BTC const & src);
		~BTC();


}


#endif
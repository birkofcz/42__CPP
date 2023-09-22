/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:52:53 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/22 14:12:25 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	(void)ac;
	(void)av;	

	BTC btc("data.csv");

	btc.printDatabase(10);
	
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/19 11:50:01 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << YEL "\nPrinting first set of size: " << sp.getSize() << std::endl;
		sp.printSet();
		std::cout << YEL "\nSpan found: " RES << std::endl;
		std::cout << GRE "Shortest span " RES << sp.shortestSpan() << std::endl;
		std::cout << GRE "Longest span " RES << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	///
	try
	{
		srand(time(NULL)); //seed for random nums
		std::set<int> set_tmp;
		while (set_tmp.size() < 1000)
			set_tmp.insert((rand() % 4000) -2000);
		
		Span sp2 = Span(set_tmp.size());
		sp2.addNumbers(set_tmp.begin(), set_tmp.end());

		std::cout << YEL "\nPrinting second set of size: " RES << sp2.getSize() << std::endl;
		sp2.printSet();
		std::cout << YEL "\nSpan found: " RES << std::endl;
		std::cout << GRE "Shortest span " RES << sp2.shortestSpan() << std::endl;
		std::cout << GRE "Longest span " RES << sp2.longestSpan() << std::endl;

		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

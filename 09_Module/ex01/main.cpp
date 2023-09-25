/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:15:12 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/25 16:21:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./RPN <reverse polish notation expression>" << std::endl;
		return 1;
	}
	int status;
	if (std::string(av[1]) == "eval")
	{
		std::cout << YEL "\n[[ SUBJECT & EVAL SHEET TESTS MODE ]]" RES << std::endl;
		std::cout << std::endl;
		std::string test1 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
		std::string test2 = "7 7 * 7 -";
		std::string test3 = "(1 + 1)";
		std::string test4 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
		std::string test5 = "9 8 * 4 * 4 / 2 + 9 - 8 - 8 -1 - 6 -";
		std::string test6 = "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /";

		std::cout << "Test 1: \"" << test1 << "\"" << std::endl;
		RPN rpn1(test1);
		status = rpn1.calculate();
		std::cout << std::endl;
		std::cout << "Test 2: \"" << test2 << "\"" << std::endl;
		RPN rpn2(test2);
		status = rpn2.calculate();
		std::cout << std::endl;
		std::cout << "Test 3: \"" << test3 << "\"" << std::endl;
		RPN rpn3(test3);
		status = rpn3.calculate();
		std::cout << std::endl;
		std::cout << "Test 4: \"" << test4 << "\"" << std::endl;
		RPN rpn4(test4);
		status = rpn4.calculate();
		std::cout << std::endl;
		std::cout << "Test 5: \"" << test5 << "\"" << std::endl;
		RPN rpn5(test5);
		status = rpn5.calculate();	
		std::cout << std::endl;
		std::cout << "Test 6: \"" << test6 << "\"" << std::endl;
		RPN rpn6(test6);
		status = rpn6.calculate();
		std::cout << std::endl;
		return status;
	}
	else
	{
		RPN rpn(av[1]);
		status = rpn.calculate();
		return status;
	}
}

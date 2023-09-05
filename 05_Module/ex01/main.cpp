/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/05 17:33:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac == 6)
	{
		try
		{
			Form form1(av[1], atoi(av[2]), atoi(av[3]));
			Bureaucrat bureau1(av[4], atoi(av[5]));

			std::cout << std::endl;
			std::cout << "Bureaucrat data:" << std::endl;
			std::cout << bureau1 << std::endl;

			std::cout << std::endl;
			std::cout << "Form data:" << std::endl;
			std::cout << form1 << std::endl;

			std::cout << std::endl << "Signing process:" << std::endl;
			try
			{
				bureau1.signForm(form1);
				form1.beSigned(bureau1); 	
			}
			catch(const std::exception& e){}
			std::cout << std::endl << form1 << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}	
	}
	else {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}	
	return 0;
}
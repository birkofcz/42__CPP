/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 10:42:56 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		try
		{
			Bureaucrat blbec1(av[1], atoi(av[2]));
			std::cout << blbec1 << std::endl;
			blbec1.gradeUp(1);
			std::cout << blbec1 << std::endl;
		}
		//catch(Bureaucrat::GradeTooHighException& e)
		catch (std::exception& e)
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
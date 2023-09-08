/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 10:56:09 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		Bureaucrat b1(av[1], atoi(av[2]));
		ShrubberyCreationForm f1("home");
		RobotomyRequestForm f2("Marvin");
		PresidentialPardonForm f3("Bob");

		std::cout << std::endl;
		std::cout << YEL << " [[[   WELCOME TO OUR LITTLE BUREAUCRATIC HELL !   ]]]" << RES << std::endl;

		std::cout << std::endl;
		std::cout << RED << "BEWARE! Bureaucrat is created with grade " << av[2] << RES << std::endl;
		std::cout << b1 << std::endl;
			
		std::cout << std::endl;
		std::cout << YEL << "Testing ShrubberyCreationForm --------------------------" << RES << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << std::endl;
		b1.executeForm(f1);

		std::cout << std::endl << std::endl;
		std::cout << YEL << "Testing RobotomyRequestForm --------------------------" << RES << std::endl;
		std::cout << f2 << std::endl;
		b1.signForm(f2);
		std::cout << std::endl;
		std::cout << f2 << std::endl;
		b1.executeForm(f2);

		std::cout << std::endl << std::endl;
		std::cout << YEL << "Testing PresidentialPardonForm --------------------------" << RES << std::endl;	
		std::cout << f3 << std::endl;
		b1.executeForm(f3);
		std::cout << std::endl;
		b1.signForm(f3);
		std::cout << std::endl;
		std::cout << f3 << std::endl;
		b1.executeForm(f3);
		std::cout << std::endl;
	}
	else {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	
	return 0;
}
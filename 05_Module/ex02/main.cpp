/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 15:16:44 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	Bureaucrat b1("Pitomec", 10);
	ShrubberyCreationForm f1("home");
	RobotomyRequestForm f2("Marvin");
	PresidentialPardonForm f3("Bob");

	std::cout << std::endl;
	std::cout << YEL << " [[[   WELCOME TO OUR LITTLE BUREAUCRATIC HELL !   ]]]" << RES << std::endl;

	std::cout << std::endl;
	std::cout << RED << "BEWARE! Bureaucrat is created with grade 10" << RES << std::endl;
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
	
	return 0;
}
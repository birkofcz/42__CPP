/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 16:00:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(int ac, char**av)
{
	if (ac == 3)
	{
		try
		{
			Intern intern;
			AForm* form;
			
			std::cout << std::endl;
			form = intern.makeForm(av[1], av[2]);
			std::cout << *form << std::endl;	
			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		return (std::cout << "Wrong number of arguments" << std::endl, 1);
	return 0;
}
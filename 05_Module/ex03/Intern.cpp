/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:24:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 16:01:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */

Intern::Intern() {}

Intern::Intern(const Intern& original)
{
	*this = original;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern(){}

///// Methods

AForm*	Intern::makeForm(std::string name, std::string target)
{
	char identifier = std::tolower(name[0]);
	std::string message = "Intern creates " + name + " form for " + target + "\n";
	// using switch statement to create form. Using first letter of name to determine which form to create
	//because switch statement does not work with strings, we are using first letter of name in its int representation
	switch (identifier)
	{
		case 'r':
			std::cout << message << std::endl;
			return new RobotomyRequestForm(target);
			break ;
		case 'p':
			std::cout << message << std::endl;
			return new PresidentialPardonForm(target);
			break ;
		case 's':
			std::cout << message << std::endl;
			return new ShrubberyCreationForm(target);
			break ;
		default:
			throw Intern::UnknownFormException();
	}
}



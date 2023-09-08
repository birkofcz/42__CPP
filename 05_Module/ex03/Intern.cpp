/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:24:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 11:36:12 by sbenes           ###   ########.fr       */
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
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* newforms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << GRE << "Intern creates " << name << " form for " << target << RES << std::endl;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete newforms[j];
			}
			return newforms[i];
		}
	}
	for (int i = 0; i < 3; i++)
		delete newforms[i];
	throw Intern::UnknownFormException();
}
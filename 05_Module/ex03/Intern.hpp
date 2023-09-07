/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:23:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 15:28:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
	
	public:
		Intern();
		Intern(const Intern& original);
		Intern &operator=(const Intern& src);
		~Intern();

		/* Methods */
		AForm*	makeForm(std::string name, std::string target);

		/* Exception classes */
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "Unknown form" RES);
				}
		};
};

#endif
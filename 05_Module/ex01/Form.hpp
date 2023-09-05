/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:29:00 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/05 16:41:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _signlimit;
		int const _executelimit;
	
	public:
		Form();
		Form(std::string name, int signlimit, int executelimit);
		Form(const Form& original);
		Form &operator=(const Form& src);
		~Form();

		/* Methods */
		void	beSigned(const Bureaucrat& bureaucrat);

		/* Getters */
		std::string	getName() const;
		std::string	getSignatureStatus() const;
		int			getSignLimit() const;
		int			getExecLimit() const;

		/* Exception classes */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "Grade is too high" RES);
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "Grade is too low" RES);
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
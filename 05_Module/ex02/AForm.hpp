/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:29:00 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 16:03:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _signlimit;
		int const _executelimit;
	
	public:
		AForm();
		AForm(std::string name, int signlimit, int executelimit);
		AForm(const AForm& original);
		AForm &operator=(const AForm& src);
		virtual ~AForm();

		/* Methods */
		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0;			//pure virtual function for ex02

		/* Getters */
		std::string	getName() const;
		bool		getSignatureStatus() const;
		int			getSignLimit() const;
		int			getExecLimit() const;

		/* Exception classes */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "grade is too high" RES);
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "grade is too low" RES);
				}
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return (RED "form is not signed" RES);
				}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
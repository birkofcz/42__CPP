/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:20:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 11:14:42 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;

	public:

		std::string	getName() const;
		int			getGrade() const;
		void		signForm(AForm& form);						//ex01 - form signing method
		void		executeForm( const AForm& form ) const;		//ex02 - form execution method

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& original);
		Bureaucrat &operator=(const Bureaucrat& src);
		~Bureaucrat();

		/* My methods */
		void	gradeUp(int howmuch);
		void	gradeDown(int howmuch);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
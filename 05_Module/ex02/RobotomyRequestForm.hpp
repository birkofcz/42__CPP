/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:21:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 14:22:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& original);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		/* Methods */
		void	execute(const Bureaucrat& executor) const; //function overriden from AForm

		/* Getters */
		std::string	getTarget() const;

};

#endif	
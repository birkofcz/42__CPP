/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:45:28 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 14:53:32 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& original);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		/* Methods */
		void	execute(const Bureaucrat& executor) const; //function overriden from AForm

		/* Getters */
		std::string	getTarget() const;
};

#endif
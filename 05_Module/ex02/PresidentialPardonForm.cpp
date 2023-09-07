/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:46:31 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 14:54:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)	
	: AForm(original), _target(original._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	(void)src;
	return *this;
}	

PresidentialPardonForm::~PresidentialPardonForm(){}

///// Methods
std::string	PresidentialPardonForm::getTarget() const {return _target;}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignatureStatus() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecLimit())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "[[ Bureaucrat ]] " << executor.getName() << " executes " << this->getName() << std::endl;
		std::cout << GRE << _target << " has been pardoned by Zafod Beeblebrox" << RES <<  std::endl;
	}
}
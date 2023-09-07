/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:19:38 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 14:44:36 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}	

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
	: AForm(original), _target(original._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	(void)src;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

///// Methods

std::string	RobotomyRequestForm::getTarget() const {return _target;}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	//random number seed
	std::srand(std::time(NULL));
	if (this->getSignatureStatus() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecLimit())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "[[ Bureaucrat ]] " << executor.getName() << " executes " << this->getName() << std::endl;
		//using random number to simulate robotomy
		if (std::rand() % 2 == 0)
			std::cout << "BZZZZZZZ...bzzzzz..." << _target << GRE << " has been robotomized successfully" << RES << std::endl;
		else
			std::cout << _target << RED << " robotomy failed" << RES << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:35:53 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/05 16:50:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
AForm::AForm()
	: _name(""), _signed(false), _signlimit(0), _executelimit(0)
{

}

AForm::AForm(std::string name, int signlimit, int executelimit)
	: _name(name), _signlimit(signlimit), _executelimit(executelimit)
{
	_signed = false;
	if (signlimit < 1 || executelimit < 1)
		throw AForm::GradeTooHighException();
	if (signlimit > 150 || executelimit > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& original)
	: _signlimit(original._signlimit), _executelimit(original._executelimit)
{
	_signed = original._signed;
}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

AForm::~AForm() {}

/* Insertion operator overload */
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	std::string status = obj.getSignatureStatus() ? (GRE "Signed" RES) : (RED "Not signed" RES);
	os << "[[ AForm ]] " << obj.getName() << ":" << std::endl << "Signature limit: " << obj.getSignLimit() << std::endl << "Execution limit: " << obj.getExecLimit() << std::endl << "Signature status: " << status << std::endl;
	return os;
}

/* Methods */

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signlimit)
		throw AForm::GradeTooLowException();
	_signed = true;
}
std::string AForm::getName() const {return _name;}

bool AForm::getSignatureStatus() const {return _signed;}
int	AForm::getSignLimit() const {return _signlimit;}
int AForm::getExecLimit() const {return _executelimit;}



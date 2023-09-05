/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:35:53 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/05 16:50:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
Form::Form()
	: _name(""), _signed(false), _signlimit(0), _executelimit(0)
{

}

Form::Form(std::string name, int signlimit, int executelimit)
	: _name(name), _signlimit(signlimit), _executelimit(executelimit)
{
	_signed = false;
	if (signlimit < 1 || executelimit < 1)
		throw Form::GradeTooHighException();
	if (signlimit > 150 || executelimit > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& original)
	: _signlimit(original._signlimit), _executelimit(original._executelimit)
{
	_signed = original._signed;
}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

Form::~Form() {}

/* Insertion operator overload */
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "[[ Form ]] " << obj.getName() << ":" << std::endl << "Signature limit: " << obj.getSignLimit() << std::endl << "Execution limit: " << obj.getExecLimit() << std::endl << "Signature status: " << obj.getSignatureStatus() << std::endl;
	return os;
}

/* Methods */

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signlimit)
		throw Form::GradeTooLowException();
	_signed = true;
}
std::string Form::getName() const {return _name;}

std::string Form::getSignatureStatus() const
{
	if (!_signed)
		return (RED "Not signed" RES);
	else
		return (GRE "Signed" RES);
}

int	Form::getSignLimit() const {return _signlimit;}
int Form::getExecLimit() const {return _executelimit;}



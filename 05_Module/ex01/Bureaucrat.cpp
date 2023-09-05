/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:42:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/05 17:03:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
Bureaucrat::Bureaucrat()
	: _name(""), _grade(0) // const values (_name) must be assigned as the class is constructed and there it is not changing
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
	: _name(original._name), _grade(original._grade) 
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{ 
	if (this != &src)
		_grade = src._grade;   //we cannot copy const values (_name), we need to leave it as it is
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

/////

/* Getters */
std::string	Bureaucrat::getName() const {return _name;}
int			Bureaucrat::getGrade()const {return _grade;}

/* Output stream insertion operator overload */
//constructed as output stream << object
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", [[ Bureaucrat ]] grade " << obj.getGrade() << ".";
	return os;
}

/* My methods */
void	Bureaucrat::gradeUp(int howmuch)
{
	std::cout << "Attempted to raise a grade by " << howmuch << std::endl;
	if (_grade - howmuch < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= howmuch;
}

void	Bureaucrat::gradeDown(int howmuch)
{
	std::cout << "Attempted to lower a grade by " << howmuch << std::endl;
	if (_grade + howmuch > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += howmuch;
}

/* ex01 */
/* TRying to sign  a form here, usimg functions and exceptions form lother class */
void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "[[ Bureaucrat ]] " << getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << getName() << " couldn't sign [[ Form ]] " << form.getName() << " because " << e.what() << std::endl;
	}
}
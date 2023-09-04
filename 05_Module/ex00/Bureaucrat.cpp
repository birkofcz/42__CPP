/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 08:42:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/04 09:22:47 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Default constructor, constructor, copy onstructor, copy assignemt constructor, destructor */
Bureaucrat::Bureaucrat()
	: _name(""), _grade(0) // const values (_name) must be assigned as the class is constructed and there it is not changing
{
	std::cout << "[[ Bureaucrat ]] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade) 
{
	std::cout << "[[ Bureaucrat ]] constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
	: _name(original._name), _grade(original._grade) 
{
	std::cout << "[[ Bureaucrat ]] copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{ 
	if (this == &src)
		return *this;
	_grade = src._grade;   //we cannot copy const values (_name), we need to leave it as it is
	std::cout << "[[ Bureaucrat ]] copy assignment constructor called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[[ Bureaucrat ]] destructor called" << std::endl;
}

/////

/* Getters */
std::string	Bureaucrat::getName() const {return _name;}
int			Bureaucrat::getGrade()const {return _grade;}

/* Output stream insertion operator overload */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", [[ Bureaucrat ]] grade " << obj.getGrade() << "." << std::endl;
	return os;
}

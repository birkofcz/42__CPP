/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:37 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 11:24:25 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* Default constructor */
WrongAnimal::WrongAnimal()
{
	this->_type = "";
	std::cout << "[[ WrongAnimal ]] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "[[ WrongAnimal ]] constructor called" << std::endl;
}
/* Copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	_type = original._type;
	std::cout << "[[ WrongAnimal ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	this->_type = src._type;
	std::cout << "[[ WrongAnimal ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
WrongAnimal::~WrongAnimal()
{
	std::cout << "[[ WrongAnimal ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	WrongAnimal::makeSound() const
{
	std::cout << "[[ WrongAnimal]] makesound() function was called" << std::endl;
	return ;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
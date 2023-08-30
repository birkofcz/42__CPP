/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:37 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 16:00:32 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* Default constructor */
WrongAnimal::WrongAnimal()
{
	this->_type = "";
	std::cout << "[[ WrongAnimal ]] default constructor called" << std::endl;
}

/* Copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	*this = original;
	std::cout << "[[ WrongAnimal ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "[[ WrongAnimal ]] copy assignment operator called" << std::endl;
	this->_type = src._type;
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
	return ;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
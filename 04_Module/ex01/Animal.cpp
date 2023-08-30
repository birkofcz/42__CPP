/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:50:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Default constructor */
Animal::Animal()
{
	this->_type = "Animal meta type";
	std::cout << "[[ Animal ]] default constructor called" << std::endl;
}

/* Copy constructor */
Animal::Animal(const Animal& original)
{
	*this = original;
	std::cout << "[[ Animal ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Animal& Animal::operator=(const Animal& src)
{
	std::cout << "[[ Animal ]] copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

/* Destructor */
Animal::~Animal()
{
	std::cout << "[[ Animal ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	Animal::makeSound() const
{
	std::cout << "[[ Animal ]] makeSound() called" << std::endl;
	return ;
}

void	Animal::readBrain(std::string name) const
{
	if (name.empty())
		return ;
	else
		return ;
}

std::string	Animal::getType() const
{
	return this->_type;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 13:44:49 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* Default constructor */
AAnimal::AAnimal()
{
	_type = "AAnimal meta type";
	std::cout << "[[ AAnimal ]] default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	_type = type;
	std::cout << "[[ AAnimal ]] constructor called" << std::endl;
}

/* Copy constructor */
AAnimal::AAnimal(const AAnimal& original)
{
	_type = original._type;
	std::cout << "[[ AAnimal ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
AAnimal& AAnimal::operator=(const AAnimal& src)
{
	_type = src._type;
	std::cout << "[[ AAnimal ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
AAnimal::~AAnimal()
{
	std::cout << "[[ AAnimal ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	AAnimal::makeSound() const
{
	std::cout << "[[ AAnimal ]] makeSound() called" << std::endl;
	return ;
}

std::string	AAnimal::getType() const {return _type;}

void	AAnimal::readBrain() const
{
	std::cout << "[[ AAnimal ]] readBrain() called" << std::endl;
	return ;
}
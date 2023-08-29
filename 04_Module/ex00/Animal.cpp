/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 14:12:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Default constructor */
Animal::Animal()
{
	this->_type = "";
	std::cout << "[[ Animal ]] default constructor called" << std::endl;
}

/* Parametric Constructor */
/* Animal::Animal(std::string type) : _type(type)
{
	std::cout << "[[ Animal ]] parametric constructor called" << std::endl;
}
 */
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
	return ;
}

std::string	Animal::getType() const
{
	return this->_type;
}
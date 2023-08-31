/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 13:09:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Default constructor */
Animal::Animal()
{
	_type = "Animal meta type";
	std::cout << "[[ Animal ]] default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "[[ Animal ]] constructor called" << std::endl;
}

/* Copy constructor */
Animal::Animal(const Animal& original)
{
	_type = original._type;
	std::cout << "[[ Animal ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Animal& Animal::operator=(const Animal& src)
{
	_type = src._type;
	std::cout << "[[ Animal ]] copy assignment operator called" << std::endl;
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

std::string	Animal::getType() const {return _type;}
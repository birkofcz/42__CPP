/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 14:39:54 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "[[ Dog ]] default constructor called" << std::endl;
}

/* Parametric Constructor */
/* Dog::Dog(std::string type) : _type(type)
{
	std::cout << "[[ Dog ]] parametric constructor called" << std::endl;
}
 */
/* Copy constructor */
Dog::Dog(const Dog& original)
{
	*this = original;
	std::cout << "[[ Dog ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Dog& Dog::operator=(const Dog& src)
{
	std::cout << "[[ Dog ]] copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

/* Destructor */
Dog::~Dog()
{
	std::cout << "[[ Dog ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	Dog::makeSound() const
{
	std::cout << "Woof...woof!" << std::endl;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 13:13:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default constructor */
Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "[[ Cat ]] default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	_type = type;
	std::cout << "[[ Cat ]] constructor called" << std::endl;
}

/* Copy constructor */
Cat::Cat(const Cat& original) : Animal(original)
{
	_type = original._type;
	std::cout << "[[ Cat ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Cat& Cat::operator=(const Cat& src)
{
	Animal::operator=(src);
	this->_type = src._type;
	std::cout << "[[ Cat ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
Cat::~Cat()
{
	std::cout << "[[ Cat ]] destructor called" << std::endl;
}

/* Member functions - methods */
//overriding function from base class
void	Cat::makeSound() const
{
	std::cout << "Meowww..." << std::endl;
	return ;
}
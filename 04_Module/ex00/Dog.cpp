/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 13:15:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "[[ Dog ]] default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	_type = type;
	std::cout << "[[ Dog ]] constructor called" << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog& original) : Animal(original)
{
	_type = original._type;
	std::cout << "[[ Dog ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Dog& Dog::operator=(const Dog& src)
{
	Animal::operator=(src);
	_type = src._type;
	std::cout << "[[ Dog ]] copy assignment operator called" << std::endl;
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
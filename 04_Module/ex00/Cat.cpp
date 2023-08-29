/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 14:12:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default constructor */
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "[[ Cat ]] default constructor called" << std::endl;
}

/* Parametric Constructor */
/* Cat::Cat(std::string type) : _type(type)
{
	std::cout << "[[ Cat ]] parametric constructor called" << std::endl;
}
 */
/* Copy constructor */
Cat::Cat(const Cat& original)
{
	*this = original;
	std::cout << "[[ Cat ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Cat& Cat::operator=(const Cat& src)
{
	std::cout << "[[ Cat ]] copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

/* Destructor */
Cat::~Cat()
{
	std::cout << "[[ Cat ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	Cat::makeSound() const
{
	std::cout << "Meowww..." << std::endl;
	return ;
}
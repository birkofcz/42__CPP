/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:04:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 16:04:49 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* Default constructor */
WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "[[ WrongCat ]] default constructor called" << std::endl;
}

/* Copy constructor */
WrongCat::WrongCat(const WrongCat& original)
{
	*this = original;
	std::cout << "[[ WrongCat ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "[[ WrongCat ]] copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

/* Destructor */
WrongCat::~WrongCat()
{
	std::cout << "[[ WrongCat ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	WrongCat::makeSound() const
{
	std::cout << "Wrong--Meowww..." << std::endl;
	return ;
}
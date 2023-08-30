/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:48:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default constructor */
Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->brain = new Brain;
	std::cout << "[[ Cat ]] default constructor called, brain created and filled with ideas" << std::endl;
}

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
	this->brain = src.brain;
	return *this;
}

/* Destructor */
Cat::~Cat()
{
	delete this->brain;
	std::cout << "[[ Cat ]] destructor called and brain deleted" << std::endl;
}

/* Member functions - methods */
void	Cat::makeSound() const
{
	std::cout << "Meowww..." << std::endl;
	return ;
}

void	Cat::readBrain(std::string name) const
{
	std::cout << name << std::endl;
	if (this->brain)
		for (int i = 1; i < 101; i++)
		{
			std::cout << (this->brain->getIdeas())[i] << " ";
			if (i == 100)
				std::cout << std::endl;
		}
}
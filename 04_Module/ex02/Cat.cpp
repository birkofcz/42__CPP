/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 14:37:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Default constructor */
Cat::Cat() : AAnimal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "[[ Cat ]] default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type)
{
	_type = type;
	_brain = new Brain();
	std::cout << "[[ Cat ]] constructor called" << std::endl;
}

/* Copy constructor */
Cat::Cat(const Cat& original) : AAnimal(original)
{
	_type = original._type;
	_brain = NULL;					// Initialize to a safe value	
	if (original._brain)			// If original._brain is not NULL
		_brain = new Brain(*original._brain);
	std::cout << "[[ Cat ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Cat& Cat::operator=(const Cat& src)
{
	AAnimal::operator=(src);
	this->_type = src._type;
	*_brain = *src._brain;  // This should trigger the copy assignment operator for Brain - correctly adding (copyassigned) to the ideas array
	std::cout << "[[ Cat ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
Cat::~Cat()
{
	delete _brain;
	std::cout << "[[ Cat ]] destructor called" << std::endl;
}

/* Member functions - methods */
//overriding function from base class
void	Cat::makeSound() const
{
	std::cout << "Meowww..." << std::endl;
	return ;
}

void	Cat::readBrain() const
{
	std::string *_ideastoread = _brain->getIdeas();
	std::cout << "Cat's brain at address " << RED << _brain << RES << " contains: ";
	for (int i = 0; i < 5; i++)
	{
		if (_ideastoread[i].empty())
			break ;
		std::cout << _ideastoread[i] << " ";
	}
		std::cout << "..." << std::endl;
}
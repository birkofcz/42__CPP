/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 14:21:12 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "[[ Dog ]] default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	_type = type;
	_brain = new Brain();
	std::cout << "[[ Dog ]] constructor called" << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog& original) : Animal(original)
{
	_type = original._type;
	_brain = NULL;  					// Initialize to a safe value
	if (original._brain) 				// If original._brain is not NULL
		_brain = new Brain(*original._brain);
	std::cout << "[[ Dog ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Dog& Dog::operator=(const Dog& src)
{
	Animal::operator=(src);
	_type = src._type;
    *_brain = *src._brain;  // This should trigger the copy assignment operator for Brain - correctly adding (copyassigned) to the ideas array
	std::cout << "[[ Dog ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
Dog::~Dog()
{
	delete _brain;
	std::cout << "[[ Dog ]] destructor called" << std::endl;
}

/* Member functions - methods */
void	Dog::makeSound() const
{
	std::cout << "Woof...woof!" << std::endl;
	return ;
}

void	Dog::readBrain() const
{
	std::string *_ideastoread = _brain->getIdeas();
	std::cout << "Dog's brain at address " << GRE << _brain << RES <<" contains: ";
	for (int i = 0; i < 5; i++)
	{
		if (_ideastoread[i].empty())
			break ;
		std::cout << _ideastoread[i] << " ";
	}
	std::cout << "..." << std::endl;
}
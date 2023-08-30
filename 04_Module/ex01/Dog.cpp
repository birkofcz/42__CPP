/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:49:15 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:53:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "[[ Dog ]] default constructor called, brain created and filled with ideas" << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog& original)
{
	this->_type = original._type;
	this->_brain = new Brain(*(original._brain)); //deep copy
	std::cout << "[[ Dog ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Dog& Dog::operator=(const Dog& src)
{
	std::cout << "[[ Dog ]] copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	delete this->_brain;
	this->_brain = new Brain(*(src._brain));  //deep_copy
	return *this;
}

/* Destructor */
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "[[ Dog ]] destructor called and brain destroyed" << std::endl;
}

/* Member functions - methods */
void	Dog::makeSound() const
{
	std::cout << "Woof...woof!" << std::endl;
	return ;
}

/* function override - reads the dog object brain, shows its heap adress*/
void	Dog::readBrain(std::string name) const
{
	if (this->_brain)
	{
		std::cout << "Reading ideas of " << name << " heap adress " << RED << static_cast<void*>(this->_brain) << RES << " :" ;
		for (int i = 0; i < 5; i++) 
		{
			std::cout << (this->_brain->getIdeas())[i+1] << " ";
			if (i == 4)
				std::cout << "..." << std::endl;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:11:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:51:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

/* Default constructor */
Brain::Brain()
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i;
		std::string number = ss.str();
		_ideas[i] = "idea(" + number + ")";
	}

	std::cout << "[[ Brain ]] is constructed and filled with ideas" << std::endl;
}

/* Copy constructor */
Brain::Brain(const Brain& original)
{
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = original._ideas[i] + "(copy)";
	//*this = original;			/// this will create a shallow copy, copying the old pointer;
	std::cout << "[[ Brain ]] copy constructor called" << std::endl;
}

/* Copy assignment operator overload */
Brain& Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		delete[] this->_ideas;
		this->_ideas = new std::string[100];
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i] + "(copy assign)" ;
	}
	std::cout << "[[ Brain ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
Brain::~Brain()
{
	delete [] _ideas;
	std::cout << "[[ Brain ]] destructor called and ideas destroyed" << std::endl;
}

std::string *Brain::getIdeas()
{
	return this->_ideas;
}



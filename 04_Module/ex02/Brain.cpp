/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:38:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 13:48:59 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

/* Default constructor */
Brain::Brain()
{
	_ideas = setIdeas();
	std::cout << "[[ Brain ]] default constructor called" << std::endl;
}

/* Copy constructor */
Brain::Brain(const Brain& original)
{
	delete[] _ideas;
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = original._ideas[i] + " (copied)";
	std::cout << "[[ Brain ]] copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
Brain& Brain::operator=(const Brain& src)
{
	delete[] _ideas;
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i] + " (copyassigned)";
	std::cout << "[[ Brain ]] copy assignment operator called" << std::endl;
	return *this;
}

/* Destructor */
Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "[[ Brain ]] destructor called" << std::endl;
}

/* Member functions - methods */
std::string	*Brain::setIdeas()
{
	std::string *ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "idea #" << i;
		ideas[i] = ss.str();
	}		
	return ideas;
}

std::string	*Brain::getIdeas() const {return _ideas;}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_experiments.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:47:36 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/28 15:52:26 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_experiments.hpp"

Warlock::Warlock(std::string const& name, std::string const& title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string&
Warlock::getName(void) const
{
	return (_name);
}

const std::string&
Warlock::getTitle(void) const
{
	return (_title);
}

void
Warlock::setTitle(const std::string& title)
{
	_title = title;
}

void
Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

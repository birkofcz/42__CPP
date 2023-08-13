/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:17:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:06:55 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


/* Constructor */
Weapon::Weapon(std::string type)
{
	this->type = type;
}

/* Destructor */
Weapon::~Weapon(){}

/* Member functions */
void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}
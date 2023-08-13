/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:44:08 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:28:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* Constructor */
HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

/* Destructor */
HumanB::~HumanB(){}

/* Member functions - methods */
void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else 
		std::cout << this->_name << " is armless, cannot attack!" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
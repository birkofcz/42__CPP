/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:44:08 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 14:04:58 by sbenes           ###   ########.fr       */
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
	std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
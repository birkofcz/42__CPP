/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:25:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 14:04:18 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* Constructor */
/* Here, we are using the initialization list to initialize member variables - good practice */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

/* Destructor */
HumanA::~HumanA(){}

/* Mamber functions */
void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
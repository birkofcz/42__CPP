/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 14:16:47 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;

	std::cout << "[[ ScavTrap ]] " << this->name << " constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[[ ScavTrap ]] " << this->name << " was destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[[ ScavTrap ]] " << this->name << " is now in gate guarding mode!" << std::endl;
}

void ScavTrap::attack(const str& target)
{
	if (energy_points <= 0)
	{
		std::cout << "[[ ScavTrap ]] " << name <<  " attempts to attack " << target << " but is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "[[ ScavTrap ]] " << name << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::report()
{
	std::cout << "[[ ScavTrap ]] " << this->name << " : " << hit_points << " HP, " << energy_points << " EP." << std::endl;
}
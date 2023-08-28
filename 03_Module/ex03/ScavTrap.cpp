/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 17:13:19 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){}

ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;

	std::cout << GRE << "[[ ScavTrap ]] " << this->name << RES << " constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << GRE <<"[[ ScavTrap ]] " << this->name << RES << " was destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << GRE << "[[ ScavTrap ]] " << this->name << RES << " is now in gate guarding mode!" << std::endl;
}

void ScavTrap::attack(const str& target)
{
	if (energy_points <= 0)
	{
		std::cout << GRE << "[[ ScavTrap ]] " << name << RES << " attempts to attack " << target << " but is out of energy points!" << std::endl;
		return ;
	}
	std::cout << GRE << "[[ ScavTrap ]] " << name << RES << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::Sreport()
{
	std::cout << GRE << "[[ ScavTrap ]] " << this->name << RES << " : " << hit_points << " HP, " << energy_points << " EP." << std::endl;
}
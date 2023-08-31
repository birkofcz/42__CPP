/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 10:53:58 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructors and destructors */
ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "[[ ScavTrap ]] " << this->name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
	std::cout << "[[ ScavTrap ]] " << this->name << " copy constructor called." << std::endl;
}

/* Overloads */
ScavTrap &ScavTrap::operator=(const ScavTrap& src)
{
	ClapTrap::operator=(src);
	std::cout << "[[ ScavTrap ]] " << this->name << " assignation operator called." << std::endl;
	return (*this);
}

/* Destructor */
ScavTrap::~ScavTrap()
{
	std::cout << "[[ ScavTrap ]] " << this->name << " was destroyed." << std::endl;
}



/* Other methods */
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

/* My methods*/
void ScavTrap::report()
{
	std::cout << "[[ ScavTrap ]] " << this->name << " : " << hit_points << " HP, " << energy_points << " EP." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:19:11 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 12:03:58 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	name = "ScavTrap( " + this->getName() + ")"; 
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "[[ ScavTrap ]] Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string trap_name) : ClapTrap(trap_name)
{
	name = "ScavTrap(" + this->getName() + ")"; //for illustration purposes, that we have the derived class name
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "[[ ScavTrap ]] Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
	name = original.name + "(copy constructed)"; //for debugging purposes
	hit_points = original.hit_points;
	energy_points = original.energy_points;	
	attack_damage = original.attack_damage;
	std::cout << "[[ ScavTrap ]] Copy Constructor called" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &src)
{
	ClapTrap::operator=(src);
	name = src.name + "(copy assigned)"; //for debugging purposes
	hit_points = src.hit_points;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;
	std::cout << "[[ ScavTrap ]] Assignement operator called" << std::endl;
	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "[[ ScavTrap ]] Destructor called" << std::endl;
}


/* =================================================================================== */

void	ScavTrap::guardGate()
{
	std::cout << "[[ ScavTrap ]] " << this->getName() << " have entered in Gate keeper mode" << std::endl;
}

/* my extra methods */
void	ScavTrap::report() const
{
	std::cout << "[[ ScavTrap ]] " << this->getName() << " HP: " << this->getHP() << " Energy: " << this->getEnergy() << std::endl;
}

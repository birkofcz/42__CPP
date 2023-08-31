/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 11:27:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructor */
ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string trap_name)
{
	name = trap_name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "[[ ClapTrap ]] " << name << " created" << std::endl;
	return ;
}

/* Copy constructor */
ClapTrap::ClapTrap(const ClapTrap& original)
{
	this->name = original.name;	
	this->hit_points = original.hit_points;	
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;
	std::cout << "[[ ClapTrap ]] COPY constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	std::cout << "[[ ClapTrap ]] copy ASIGNMENT operator called" << std::endl;
	return *this;
}

/* Destructor */
ClapTrap::~ClapTrap()
{
	std::cout << "[[ ClapTrap ]] " << name << " destroyed" << std::endl;
}

/* ================================================================================================================================ */

/* Member functions - methods */
void ClapTrap::attack(const std::string &target)
{
	if (energy_points <= 0)
	{
		std::cout << "[[ ClapTrap ]] " << name <<  " attempts to attack " << target << " but is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "[[ ClapTrap ]] " << name << " attacks " << target << " causing " <<  attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= amount)
	{
		std::cout << "[[ ClapTrap ]] " << name << " has taken " << amount << " points of damage" << std::endl;
		std::cout << "[[ ClapTrap ]] " << name << " is destroyed!" << std::endl;
		return ;
	}
	std::cout << "[[ ClapTrap ]] " << name << " has taken " << amount << " points of damage" << std::endl;
	hit_points -= amount; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= amount)
	{
		std::cout << "[[ ClapTrap ]] " << name << "attempted to repair itself but is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "[[ ClapTrap ]] " << name << " repairs itself for " << amount << " hit points" << std::endl;
	hit_points += amount;
	energy_points--;
}

/* MY ADDITIONAL FUNCTIONS FOR TEST PURPOSES */
std::string	ClapTrap::getName() const {return this->name;}
int			ClapTrap::getHP() const {return this->hit_points;}
int			ClapTrap::getEnergy() const {return this->energy_points;}
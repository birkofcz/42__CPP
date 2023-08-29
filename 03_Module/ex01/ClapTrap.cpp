/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:57 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 14:01:01 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructor */
ClapTrap::ClapTrap(str trap_name) : name(trap_name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "[[ ClapTrap ]] " << this->name << " constructor called" << std::endl;
}

/* Copy constructor */
ClapTrap::ClapTrap(const ClapTrap& original)
{
	*this = original;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return ;
}

/* Copy assignment operator overload */
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return *this;
}

/* Destructor */
ClapTrap::~ClapTrap()
{
	std::cout << "[[ ClapTrap ]] " << this->name << " was destroyed." << std::endl;
}

/* Member functions - methods */
void ClapTrap::attack(const str&target)
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
str ClapTrap::getName()
{
	return this->name;
}

int ClapTrap::getHP()
{
	return this->hit_points;
}

int ClapTrap::getEnergy()
{
	return this->energy_points;
}

/* void attack(const str& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap(str trap_name);
		ClapTrap(const ClapTrap& original);
		ClapTrap &operator=(const ClapTrap& src);
		~ClapTrap(); */
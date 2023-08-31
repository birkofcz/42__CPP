/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:39:20 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 12:40:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	name = "FragTrap( " + this->getName() + ")"; 
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "[[ FragTrap ]] Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string trap_name) : ClapTrap(trap_name)
{
	name = "FragTrap(" + this->getName() + ")"; //for illustration purposes, that we have the derived class name
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "[[ FragTrap ]] Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original)
{
	name = original.name + "(copy constructed)"; //for debugging purposes
	hit_points = original.hit_points;
	energy_points = original.energy_points;	
	attack_damage = original.attack_damage;
	std::cout << "[[ FragTrap ]] Copy Constructor called" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &src)
{
	ClapTrap::operator=(src);
	name = src.name + "(copy assigned)"; //for debugging purposes
	hit_points = src.hit_points;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;
	std::cout << "[[ FragTrap ]] Assignement operator called" << std::endl;
	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "[[ FragTrap ]] Destructor called" << std::endl;
}


/* =================================================================================== */

void	FragTrap::highFiveGuys()
{
	std::cout << "[[ FragTrap ]] " << this->getName() << " wants to high five" << std::endl;
}

/* my extra methods */
void	FragTrap::report() const
{
	std::cout << "[[ FragTrap ]] " << this->getName() << " HP: " << this->getHP() << " Energy: " << this->getEnergy() << std::endl;
}

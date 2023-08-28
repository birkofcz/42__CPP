/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 17:13:50 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){}

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;

	std::cout << YEL << "[[ FragTrap ]] " << this->name << RES << " constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << YEL << "[[ FragTrap ]] " << this->name << RES << " was destroyed." << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << YEL << "[[ FragTrap ]] " << this->name << RES << " is reguesting a high-five!" << std::endl;
}

void FragTrap::attack(const str& target)
{
	if (energy_points <= 0)
	{
		std::cout << YEL << "[[ FragTrap ]] " << name << RES << " attempts to attack " << target << " but is out of energy points!" << std::endl;
		return ;
	}
	std::cout << YEL << "[[ FragTrap ]] " << name << RES << " attacks " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void FragTrap::Freport()
{
	std::cout << YEL << "[[ FragTrap ]] " << this->name << RES << " : " << hit_points << " HP, " << energy_points << " EP." << std::endl;
}
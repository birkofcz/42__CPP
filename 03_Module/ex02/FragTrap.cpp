/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 14:38:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;

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

void FragTrap::report()
{
	std::cout << YEL << "[[ FragTrap ]] " << this->name << RES << " : " << hit_points << " HP, " << energy_points << " EP." << std::endl;
}
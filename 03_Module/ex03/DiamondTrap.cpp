/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:21 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 17:20:06 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <typeinfo>

DiamondTrap::DiamondTrap(){}

DiamondTrap::DiamondTrap(str name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "In Constructor of " << typeid(*this).name() << ": hit_points=" << hit_points << ", energy_points=" << energy_points << std::endl;


	std::cout << BLUE << "[[ DiamondTrap ]] " << this->name << RES << " constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << "[[ DiamondTrap ]] " << this->name << RES << " was destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << BLUE << "[[ DiamondTrap ]] " << this->name << RES << " : my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::Dreport()
{
	std::cout << BLUE << "[[ DiamondTrap ]] " << this->name << RES << " : " << DiamondTrap::hit_points << " HP, " << DiamondTrap::energy_points << " EP." << std::endl;
}
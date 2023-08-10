/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:28:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/10 14:20:42 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() // constructor
{
	this->name = "";
}

Zombie::~Zombie() // destruktor
{
	std::cout << "Zombie " << this->name << " was destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ.." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
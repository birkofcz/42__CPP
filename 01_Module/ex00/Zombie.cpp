/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:28:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/07 14:27:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) // constructor
{
	this->name = name;
}

Zombie::~Zombie() // destruktor
{
	std::cout << "Zombie " << this->name << " was destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ.." << std::endl;
}
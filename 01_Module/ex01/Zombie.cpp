/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:28:58 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:21:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "";
}

Zombie::~Zombie(){};

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(int num)
{
	std::cout << sb_toupper_str(this->name) << " " << num  << ":" << " BraiiiiiiinnnzzzZ.." << std::endl;
}

std::string sb_toupper_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += toupper(src[i]);
	return (result);
}
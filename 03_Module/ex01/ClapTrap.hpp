/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 10:45:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

/* ..so you dont have to write this all over again.. */
typedef std::string str;

class ClapTrap
{
	protected:									// for inheritance, this needs to be changed to protected
		str				name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:
		void attack(const str& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/* my additional functions for testing purposes */
		str getName();
		int getHP();
		int getEnergy();

		ClapTrap(str trap_name);
		ClapTrap(const ClapTrap& original);
		ClapTrap &operator=(const ClapTrap& src);
		~ClapTrap();
	
};

#endif
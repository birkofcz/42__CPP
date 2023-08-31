/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 11:13:28 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRE << "Creation ..." << RES << std::endl;
	ClapTrap x111("x111");
	ClapTrap x214("x214");

	std::cout << std::endl;
	std::cout << GRE << "Testing ..." << RES << std::endl;

	std::cout << "[[ ClapTrap ]] " << x111.getName() << " has " << x111.getHP() << " hit points and " << x111.getEnergy() << " energy." << std::endl;
	std::cout << "[[ ClapTrap ]] " << x214.getName() << " has " << x214.getHP() << " hit points and " << x214.getEnergy() << " energy." << std::endl;
	std::cout << YEL;
	x111.attack("mause1");
	x111.attack("mause2");
	x111.attack("mause3");
	x111.attack("mause4");
	x111.attack("mause5");
	x111.attack("mause6");
	x111.attack("mause7");
	x111.attack("mause8");
	x111.attack("mause9");
	x111.attack("mause10");
	std::cout << RES;
	std::cout << "[[ ClapTrap ]] " << x111.getName() << " has " << x111.getEnergy() << " energy" << std::endl;\
	std::cout << YEL;
	x111.attack("mouse11");
	std::cout << RED;
	x214.takeDamage(6);
	std::cout << RES;
	std::cout << "[[ ClapTrap ]] " << x214.getName() << " has " << x214.getHP() << " hit points"<< std::endl;
	std::cout << YEL;
	x214.attack("deer");
	std::cout << RES;
	std::cout << "[[ ClapTrap ]] " << x214.getName() << " has " << x214.getEnergy() << " energy" << std::endl;
	std::cout << GRE;
	x214.beRepaired(4);
	std::cout << RES;
	std::cout << "[[ ClapTrap ]] " << x214.getName() << " has " << x214.getEnergy() << " energy" << std::endl;
	std::cout << "[[ ClapTrap ]] " << x214.getName() << " has " << x214.getHP() << " hit points"<< std::endl;
	std::cout << RED;
	x111.takeDamage(10);
	std::cout << RES;

	std::cout << std::endl;
	std::cout << GRE << "Destruction ..." << RES << std::endl;


	return 0;
}
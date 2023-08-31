/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 12:57:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRE << "Creation ..." << RES << std::endl;
	ScavTrap scav1("scav1");
	ScavTrap scav2("scav2");
	ScavTrap scav3(scav1);
	ScavTrap scav4;

	scav4 = scav2;			// copy assignment operator overload - if called lik ScavTrap scav4 = scav2; it is not a copy assignment operator overload but a copy constructor

	std::cout << std::endl;
	std::cout << GRE << "Testing ..." << RES << std::endl;
	scav1.report();
	scav2.report();
	scav3.report();
	scav4.report();
	scav1.attack("scav2");
	scav1.report();
	scav2.takeDamage(20);
	scav2.report();
	scav2.beRepaired(10);
	scav2.report();
	scav1.guardGate();

	std::cout << std::endl;
	std::cout << GRE << "Destruction ..." << RES << std::endl;


	return 0;
}
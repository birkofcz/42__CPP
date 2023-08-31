/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 12:55:06 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRE << "Creation ..." << RES << std::endl;
	ScavTrap scav1("scav1");
	FragTrap frag1("frag1");
	FragTrap frag2(frag1);
	FragTrap frag3;
	frag3 = frag1;

	std::cout << std::endl;
	std::cout << GRE << "Testing ..." << RES << std::endl;
	scav1.report();
	frag1.report();
	frag2.report();
	frag3.report();
	scav1.attack("frag1");
	scav1.report();
	frag1.takeDamage(20);
	frag1.report();
	frag1.attack("scav1");
	frag1.report();
	scav1.takeDamage(30);
	scav1.report();
	frag1.beRepaired(10);
	scav1.beRepaired(10);
	frag1.report();
	scav1.report();
	frag1.highFiveGuys();
	scav1.guardGate();

	std::cout << std::endl;
	std::cout << GRE << "Destruction ..." << RES << std::endl;

	return 0;
}
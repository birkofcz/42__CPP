/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 11:39:58 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <unistd.h>

int main()
{
	std::cout << std::endl;
	std::cout << "Creation ..." << std::endl;
	ScavTrap scav1("scav1");
	FragTrap frag1("frag1");

	scav1.report();
	frag1.report();
	scav1.attack("frag1");
	scav1.report();
	frag1.takeDamage(20);
	frag1.report();
	frag1.attack("scav1");
	frag1.report();
	scav1.takeDamage(30);
	scav1.report();
	frag1.highFiveGuys();
	scav1.guardGate();

	std::cout << std::endl;
	std::cout << "Destruction ..." << std::endl;

	return 0;
}
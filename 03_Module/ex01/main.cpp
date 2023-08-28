/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 14:17:31 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <unistd.h>

int main()
{
	ScavTrap scav1("scav1");
	ScavTrap scav2("scav2");

	scav1.report();
	scav2.report();
	scav1.attack("scav2");
	scav1.report();
	scav2.takeDamage(20);
	scav2.report();
	scav1.guardGate();


	return 0;
}
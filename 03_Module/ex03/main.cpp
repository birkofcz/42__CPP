/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 17:12:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <unistd.h>

int main()
{
	DiamondTrap diamond1("diamond1");
	DiamondTrap diamond2("diamond2");

	diamond1.Dreport();
	diamond1.whoAmI();
	diamond2.Dreport();
	diamond2.whoAmI();


	return 0;
}
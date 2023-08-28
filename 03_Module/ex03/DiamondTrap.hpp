/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:29:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 17:11:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		str name;
		DiamondTrap();
		
	public:

		DiamondTrap(str name);
		virtual ~DiamondTrap();
		void	whoAmI();
		void	Dreport(); 			//my own function to report HP and EP of the trap
		using ScavTrap::attack;
};

#endif
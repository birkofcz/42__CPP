/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:42:46 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 14:02:21 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string _name;
		Weapon* 	_weapon;

	public:
		void attack();
		void setWeapon(Weapon& weapon);

	HumanB(std::string name);
	~HumanB();
};

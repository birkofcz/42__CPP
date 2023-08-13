/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:21:28 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:08:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
		
	public:
		void attack();

	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};

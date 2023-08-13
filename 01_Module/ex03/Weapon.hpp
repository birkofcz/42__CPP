/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:08:28 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:06:21 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class	Weapon
{
	private:
		std::string type;
	
	public:
		const std::string&		getType(); // returns ref to type
		void				setType(std::string type); // sets type to type taken as parameter
	
	Weapon(std::string type);
	~Weapon();
};

#endif

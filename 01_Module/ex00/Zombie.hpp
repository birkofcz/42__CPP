/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:43:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/10 14:11:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

/* Classes definitions */
class Zombie
{
	private:
	std::string name;

	public:
	void announce();
	void setName(std::string name);

	Zombie(); //Constructor
	~Zombie(); //Destructor
};

/* Functions */
Zombie *newZombie(std::string name);
void randomChump(std::string name);


#endif
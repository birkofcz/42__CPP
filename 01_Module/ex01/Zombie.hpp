/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:43:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/09 17:01:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <cstdlib> 

/* Classes definitions */

class Zombie
{
	private:
	std::string name;

	public:
	void announce(int num);
	void setName(std::string name);

	Zombie(); //Constructor
	~Zombie(); //Destructor

	//Zombie *zombieHorde(int N, std::string name);
};

/* Functions */
Zombie		*zombieHorde(int N, std::string name);
std::string	sb_toupper_str(std::string src);

#endif
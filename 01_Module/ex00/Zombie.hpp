/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:43:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/29 11:42:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

/* Classes definitions */

class Zombie
{
	void Zombie( void ); //Constructor
	void ~Zombie( void ); //Destructor

	private:
	std::string name;

	public:
	void announce( void );
};

/* Functions */

Zombie *newZombie( std::string name );
void randomChump( std::string name );


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:14:52 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 15:17:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "\n\033[31m" << "Zombies & Brainzz pt. 1" << "\033[0m" << std::endl;

	std::cout << "\nCreating zombie on the stack ..." << std::endl;
	randomChump("stack_zombie");
	// here the stack zombie is destroyed automtically by the object destructor (message will appear)
	
	std::cout << "\nCreating zombie on the heap ..." << std::endl;
	Zombie *heap_zombie = newZombie("heap_zombie");
	heap_zombie->announce();
	std::cout << "\nDestroying the heap zombie with \"delete\"..." << std::endl;
	delete heap_zombie;
	return (0);
}
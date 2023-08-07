/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:14:52 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/07 14:25:58 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* int	main()
{
	Zombie	stack_zombie("STACK");
	Zombie *heap_zombie = newZombie("HEAP");

	randomChump
	heap_zombie->announce();

	delete heap_zombie;
	return (0); // here the stack_zombie is destroyed;\

} */

int main( void ) {
    std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie zombi1(name);
    
    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie *zombi2 = newZombie(name);
    zombi2->announce();
    delete zombi2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("randomChump");
    return 0;
}
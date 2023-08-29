/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 16:15:16 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << GRE << "Creating ... " << RES << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << GRE << "Types & sounds ... " << RES << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound(); 
	meta->makeSound();
	

	/* destructing */
	std::cout << GRE << "Destructing ..." << RES << std::endl;
	delete meta;
	delete i;
	delete j;
	return 0;
}
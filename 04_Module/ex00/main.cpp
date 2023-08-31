/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 13:24:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRE << "Creating ... " << RES << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;
	std::cout << GRE << "Types & sounds ... " << RES << std::endl;
	std::cout << "type: " << meta->getType() << " " << std::endl;
	std::cout << "type: " << dog->getType() << " " << std::endl;

	std::cout << k->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound(); 
	meta->makeSound();
	k->makeSound();
	
	std::cout << std::endl;
	std::cout << GRE << "Destructing ..." << RES << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete k;
	return 0;
}
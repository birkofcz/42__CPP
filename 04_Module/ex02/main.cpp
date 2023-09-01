/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 14:41:25 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GRE << "Creating ... " << RES << std::endl;
	const AAnimal* dog1 = new Dog();
	const AAnimal* dog2 = new Dog();
	//AAnimal test;
	Dog	dog3;
	Dog	dog4(dog3);
	Dog	dog5;
	dog5 = dog3;
	const AAnimal* cat1 = new Cat();
	const AAnimal* cat2 = new Cat();
	Cat	cat3;
	Cat	cat4(cat3);
	Cat	cat5;		
	cat5 = cat3;
	
	//this will read brains of all the animals amd shows the memory address of the brain
	//to check if the brain is unique for each animal - that its not a shallow copy
	std::cout << std::endl;
	std::cout << GRE << "Reading brains ... " << RES << std::endl;
	dog1->readBrain();
	dog2->readBrain();
	dog3.readBrain();
	dog4.readBrain();
	dog5.readBrain();
	cat1->readBrain();
	cat2->readBrain();
	cat3.readBrain();
	cat4.readBrain();
	cat5.readBrain();


/* 	std::cout << std::endl;
	std::cout << GRE << "Creating array of animals ..." << RES << std::endl;
	const Animal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	
	std::cout << std::endl;
	std::cout << GRE << "Reading brains of animals ..." << RES << std::endl;
	animals[0]->readBrain();
	animals[1]->readBrain();
	animals[2]->readBrain();
	animals[3]->readBrain();

	std::cout << std::endl;
	std::cout << GRE << "Destructing array of animals ..." << RES << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
	*/

	std::cout << std::endl;
	std::cout << GRE << "Destructing ..." << RES << std::endl;
	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;

	return 0;


	 
}
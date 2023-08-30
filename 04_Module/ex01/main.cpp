/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:56 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:46:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << GRE << "Creating ... " << RES << std::endl;
/* 	const Animal* dog1 = new Dog();
	const Animal* dog2 = new Dog();
	const Animal* dog2copy = dog2; */
	//const Animal* dog1copy = dog1;
	/*const Animal* cat1 = new Cat();
	const Animal* cat1copy = cat1;
 */
	Dog dog1;
	Dog dog2;

	dog2 = dog1;
	dog1.readBrain("dog1");
	dog2.readBrain("dog2");

	/* destructing */
/* 	delete dog1;
	delete dog2;
	delete dog2copy; */
}
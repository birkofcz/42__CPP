/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:19:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/29 16:47:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parametric and copy constructors */
#include <iostream>

class Person 
{
	private:
	std::string name;
	int			age;

	public:
	Person(std::string name, int age); //parametric constructor
	~Person(void); // destructor
	void saveName(std::string name);
	void saveAge(int age);
	void printOut(void);

};

/* Definition of parametric constructor - gives values to private attributes when initiated */
Person::Person(std::string name, int age)
{
	saveName(name);
	saveAge(age);
}

/* Destructor - called last to end the class, frees the memory */
Person::~Person()
{
	std::cout << "Person deleted..." << std::endl;
}

void Person::saveName(std::string givename)
{
	name = givename;
}

void Person::saveAge(int giveage)
{
	age = giveage;
}

void Person::printOut()
{
	std::cout << "Name: " << name << ", age: " << age << std::endl;
}


int main()
{
	Person a("Alice", 30); //initiates Person a with attributes;
	Person b("Bob", 25); //initiates Person b with attributes;
	Person c(a); //initiate Person c as a copy of Person a (using copy-constructor)

	a.printOut();
	b.printOut();
	c.printOut();

	return 0;
}
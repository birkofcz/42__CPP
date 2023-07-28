/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encapsulation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/28 15:01:56 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Encapsulation is a combination of variables inside the class and member funtion 
in this class working only with those member variables. 
Why, why?
 - inreased security
 - control over modifications of our data members
 */

#include <iostream>

class Person
{
	private:
	std::string name; // you cannot access this variable directly from outside of the class

	public:
	void setName(std::string argname) // externally you use this to asign value to the private variable
	{
		name = argname;
	}

	void printName() { std::cout << name << std::endl; }
};

int main(void)
{
	Person person1;
	Person person2;

	person1.setName("Alice");
	person1.printName();

	person1.setName("Alice2");
	person1.printName();

	person2.setName("John");
	person2.printName();

	// person1.name = "Greg"; This wont work as we cannot access the variable itself.

	return 0;
}
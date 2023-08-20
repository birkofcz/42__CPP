/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:02:39 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/20 16:25:08 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
What is Inheritance?
Inheritance allows you to create a new class that is based on an existing class. 
The new class inherits attributes and behaviors (i.e., fields and methods) from the existing class.

Terminology:
1) Base Class (or Parent Class): The class whose properties and methods are inherited by another class.
2) Derived Class (or Child Class): The class that inherits the properties and methods from another class.

Why Use Inheritance?
1) Reusability: Instead of rewriting the same code, you can inherit properties and methods from an existing class.
2) Extensibility: You can add new features to a class without modifying the existing code.
3) Real-world Relationships: Inheritance models the "is-a" relationship. For example, a "Car" is a "Vehicle".

Access Specifiers and Inheritance:
When inheriting from a base class, the derived class can access members of the base class based on their access specifiers:

1)Public Members: Are accessible in the derived class.
2)Protected Members: Are accessible in the derived class.
3)Private Members: Are NOT accessible directly from the derived class.

Important Points:
1) Constructor and Destructor: The derived class does not inherit the constructor and destructor of the base class.
However, the constructor and destructor of the base class are automatically called when an object of the derived class is created or destroyed.
2) Function Overriding: If the derived class has a function with the same name as a function in the base class, 
the function in the derived class overrides the one in the base class.
 */

#include <iostream>

class Animal 
{
	private:
		std::string name;

	protected:
		int age;

	public:
		void setName(std::string name){this->name = name;}
		void getName(){std::cout << name << std::endl;}
		void setAge(int age){this->age = age;}
		void getAge(){std::cout << age << std::endl;}
		
		void eat(){std::cout << "I can eat!" << std::endl;}
};

class Dog : public Animal 
{
	public:
		void bark(){std::cout << "I can bark!" << std::endl;}
};

int main() 
{
	Animal myAnimal;
	Dog myDog;
	
	myAnimal.setName("Kocicka");
	myAnimal.getName();
	myAnimal.setAge(2);
	myAnimal.getAge();
	myAnimal.eat();
	
	myDog.setAge(3);	//can get to tgis attribute directly
	myDog.getAge();
	myDog.eat();  // Inherited from Animal class
	myDog.bark(); // Specific to Dog class
	return 0;
}

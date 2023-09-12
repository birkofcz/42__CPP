/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:46:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 14:56:07 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"
// For dynamix_cast<> there needs to be a polymorphic class - in other words, at least one 
// virtual function in the base class.
Base::~Base() {}

/* 
std::rand() % 3 returns a random number between 0 and 2.
There is no need for a break statement after a return statement.
 */
Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (std::cout << "A created" << std::endl, new A);
		case 1:
			return (std::cout << "B created" << std::endl, new B);
		case 2:
			return (std::cout << "C created" << std::endl, new C);
		default:
			return (NULL);
	}
}

/* 
Identify from pointer.
The dynamic_cast<> operator is used to perform a conversion from pointer to pointer.
If the conversion is not possible, it returns a null pointer to indicate that the conversion failed.
If the conversion is possible, it returns a pointer to the object of the requested type.
In this case, we are trying a downcasting from Base to A, B and C = it will check at the runtime
if the object is of the requested type. If not, it will return a null pointer.
 */
void identifyFromPtr(Base* base)
{
	if (dynamic_cast<A*>(base) != NULL)
		std::cout << "A identified from a pointer cast" << std::endl;
	else if (dynamic_cast<B*>(base) != NULL)
		std::cout << "B identified from a pointer cast" << std::endl;
	else if (dynamic_cast<C*>(base) != NULL)
		std::cout << "C identified from a pointer cast" << std::endl;
}

//I case of reference, the dynamic_cast<> is also used, but now it is unable to return a null pointer.
//Instead, it throws an exception of type std::bad_cast.
//WE need to use try/catch block to catch the exception, also void cast is needed to avoid the warning
// of the compiler about unused variable.
void identifyFromRef(Base& base)
{
	try 
	{
		A& test = dynamic_cast<A&>(base);
		std::cout << "A identified from a reference cast" << std::endl;
		(void)test;
	}
	catch(const std::exception& e) {}
	
	try 
	{
		B& test = dynamic_cast<B&>(base);
		std::cout << "B identified from a reference cast" << std::endl;
		(void)test;
	}
	catch( const std::exception& e ) {}
	
	try 
	{
		C& test = dynamic_cast<C&>(base);
		std::cout << "C identified from a reference cast" << std::endl;
		(void)test;
	}
	catch( const std::exception& e ) {}
}

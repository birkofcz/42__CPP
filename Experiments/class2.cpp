/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:10:10 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/26 11:53:33 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "class2.hpp"

/* Constructors and destructors - they dont have any datatype or return type. */

Sample::Sample(void) //this is a constructor. Using keyword "this". It is a pointer to current instance.
{
	std::cout << "Constructor called" << std::endl;

	//we can initialize things in constructor - using "this" as a pointer to a current instance
	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;
	
	this->bar();

	return ;
}

Sample::~Sample(void) //this is a destructor. It is called automatically at the end.
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::bar(void)
{
	std::cout << "Member function called" << std::endl;
	return;
}

int main(void)
{
	Sample instance;

	return 0;
}
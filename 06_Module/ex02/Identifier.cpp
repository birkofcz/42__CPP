/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:46:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 12:01:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Base::~Base() {}

/* 
std::rand() % 3 returns a random number between 0 and 2.
There is no need for a break statement after a return statement.
 */
Base* generate(void)
{
	switch (int random = rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
}

/* 
Identify from pointer.
How is it working?
The dynamic_cast<> operator is used to perform a conversion from pointer to pointer.
If the conversion is not possible, it returns a null pointer to indicate that the conversion failed.
If the conversion is possible, it returns a pointer to the object of the requested type.
 */
void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}


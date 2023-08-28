/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_destructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:38:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/28 15:54:59 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Base {
public:
	Base() { std::cout << "Base Constructor\n"; }
	virtual ~Base() { std::cout << "Base Destructor\n"; }
	void announce()
	{
		std::cout << "Hello from Base" << std::endl;
	}
};

class Derived : public Base {
public:
	Derived() { std::cout << "Derived Constructor\n"; }
	~Derived() { std::cout << "Derived Destructor\n"; }
	void announce()
	{
		std::cout << "Hello from Derived" << std::endl;
	}
};

int main() {

	//here we have a pointer to Derived instance b - when made this way, we need to make a destructor virtual
	// because if not, only a destructor in Base will be called when we deleting b - leaving unexpeted bahviour and possible leaks of resources.
	Base* b = new Derived();
	
	b->announce();
	
	//delete b;  // This will first call the Derived destructor and then the Base destructor
	return 0;
}

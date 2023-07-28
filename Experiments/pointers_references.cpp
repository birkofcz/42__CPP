/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_references.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:34:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/28 16:41:20 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Differences arround pointers and references */
// C++ Program to demonstrate
// use of references

/* 
Internally, references are implemented as pointers - done by a compiler.

// Pointers: //

Can be reassigned to another memory location.
Can be null.
More powerful, can point to a memory location directly.
Can be iterated over an array.
Can be manipulated (point to different things).
Pointers can be array of pointers.
Pointers can be created without initialization.
Need to be dereferenced to access the value they point to.

// References: //

Cannot be reassigned once initialized.
Cannot be null.
Less powerful, but easier to use and safer.
Cannot be iterated over an array.
Cannot be manipulated (always refer to the same thing).
There's no such thing as array of references.
Must be initialized when created.
Can be used directly to access the value they refer to.


this explains a lot:

 /// "&" is a ADDRESS-OF operator///
 */
#include <iostream>

int main()
{
	int x = 10;


	// ref is a reference to x.
	int &ref = x;
	int *ptr = &x;

	std::cout << "x = " << x << std::endl;
	std::cout << "Address of x =  " << &x << std::endl;
	std::cout << "Ptr to x =  " << ptr << std::endl;
	std::cout << "Address of ptr =  " << &ptr << std::endl;

	std::cout << "Dereferenced ptr to x =  " << *ptr << std::endl;

	std::cout << "Address of ref to x =  " << &ref << std::endl;


	// Value of x is now changed to 20 through the reference
	ref = 20;
	std::cout << "reasigning ref = 20. x = " << x << std::endl;

	// Value of x is now changed to 30 through the variable itself
	x = 30;
	std::cout << "Reasigning x = 30. ref = " << ref << std::endl;

	return 0;
}

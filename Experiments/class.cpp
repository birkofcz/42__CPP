/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:45:22 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/13 14:15:43 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This is the header file of all standard header files in C++ 
 - might not work with some compilers - but worth the try? */
#include <iostream>

/* CLASS - is the base of object-oriented programming. Class is user-defined data
structure, it has it's own ATTRIBUTES (data members) and BEHAVIOUR (member functions). 
Class is a template for an object (like "animal" is a class and "dog" is an object)*/

using namespace std;

class AddingNumbers
{
public:

	int a;
	string b;

	AddingNumbers(): a(5), b("Hello") {}

	int addnums(int x, int y)
	{
		return x + y;
	}
};

int	main()
{
	AddingNumbers test;

	cout << "Printing test integer from class AddingNumbers: " << test.a << endl;
	cout << "Printing test string from class AddingNumbers: " << test.b << endl;
	int result = test.addnums(25, 50);
	cout << "Result of class AddingNumbers functon 'addnums(int x, int y): " << result << endl;
	return 0;
}


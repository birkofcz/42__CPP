/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:38:32 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/26 11:02:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
/*
 A namespace in C++ is used to provide a scope or a region where we define identifiers. 
It is used to avoid name conflicts between two identifiers as only unique names can be used 
as identifiers.
namespace std - statement for specifying that we will be the standard namespace where 
all the standard library functions are defined.
 */

int	main()
{
	int a = 2; //variable declarations
	int b = 3;
	int result = a + b; // expressions
	string word;

	cout << "Hello, World!" << endl;
	cout << "Result: " << result << endl; //output
	cout << "write a word to repeat: ";
	cin >> word;
	cout << "You entered: [" << word << "]" << endl;
	return 0;
}
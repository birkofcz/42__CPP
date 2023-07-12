/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:38:32 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/12 16:46:44 by sbenes           ###   ########.fr       */
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

	cout << "Hello, World!" << endl;
	cout << "Result: " << result << endl; //output
	return 0;
}
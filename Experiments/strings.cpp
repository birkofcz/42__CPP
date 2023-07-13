/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:39:38 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/13 17:16:56 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Here are some key characteristics of C++ strings:

Dynamic size: Unlike arrays in C, C++ strings can dynamically adjust their 
size as needed. You don't have to specify the length of a string explicitly; 
it can grow or shrink dynamically based on the operations you perform on it.

Null-terminated: C++ strings are null-terminated by default, meaning they are 
internally represented as an array of characters with a null character ('\0') 
at the end. This allows them to be easily converted to C-style strings when necessary.

Member functions and operators: The std::string class provides various member 
functions and operators that make string manipulation more convenient. You can 
easily concatenate strings using the + operator or compare them using relational 
operators like == and <.

Standard Library support: C++ strings are part of the Standard Library, which 
means you can leverage the library's functions and algorithms for efficient string 
handling. For example, you can use functions like std::find, std::replace, or 
std::substr to perform common string operations. */

#include <iostream>
#include <string>

using namespace std;

/* This function is also written as sb_tolower_str in my_utils.cpp - to be used in c++ projects */
string tolower_str(string src)
{
	string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]); //we need to (and CAN do it!) append each character to 
								// result string. There is no need to dynamically allocate mem.
	return (cout << result << endl, result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		string word = tolower_str(av[1]);
		if (word == "hello")
			cout << "Thank you for a greeting!" << endl;
		else
			cout << "Not the right word!" << endl;
	}
	return 0;
}




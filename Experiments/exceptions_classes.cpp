/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions_classes.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:55:02 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/04 17:06:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

// You can also create your own exception classes by inheriting from std::exception.
// The class std::exception is a base class for all standard exceptions.
// It is defined in the <exception> header.

//Explanation:
/* class NegativeNumberException : public std::exception

We are defining a new class called NegativeNumberException that is publicly derived 
from the standard C++ exception class std::exception. This means our custom exception 
class inherits the behavior and structure of the base class.

public: This indicates that the following members (such as methods) are accessible from outside the class.
virtual const char* what() const throw()

virtual: The virtual keyword is used to declare that this function can be overridden by 
derived classes. This is important because we're providing our own implementation of 
the what() function that we want to use in our custom exception class.

const char* what() const throw(): This is the function signature of the what() method 
that we're overriding from the std::exception class.

const char*: This specifies that the return type of the function is a pointer to a 
constant character array (C-style string).

const: The const qualifier indicates that the function does not modify the state of 
the object it's called on. This is important because the what() method is supposed to 
be a read-only operation.

throw(): This is the exception specification that specifies the function doesn't throw 
any exceptions. In modern C++, this is not required, and it's optional. If an exception 
is thrown from a function that's specified as not throwing exceptions, the program will terminate.

Function Body:

Inside the what() method, we provide an implementation that simply returns the C-style string
 "Negative numbers are not allowed". This is the error message associated with our custom exception. */
class NegativeNumberException : public std::exception 
{
	public:
    	virtual const char* what() const throw()
		{
       		return "Negative numbers are not allowed";
		}
};

int main() 
{
    try 
	{
        int number;
        std::cout << "Enter a positive number: ";
        std::cin >> number;

        if (number < 0) {
            throw NegativeNumberException();
        }

        std::cout << "You entered: " << number << std::endl;
    } 
	catch (const NegativeNumberException& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

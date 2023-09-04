/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:53:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/04 13:15:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

/* Exceptions provide a way to react to exceptional circumstances (like runtime errors) 
in programs by transferring control to special functions called handlers.

To catch exceptions, a portion of code is placed under exception inspection. 
This is done by enclosing that portion of code in a try-block. When an exceptional 
circumstance arises within that block, an exception is thrown that transfers the 
control to the exception handler. If no exception is thrown, the code continues normally 
and all handlers are ignored.

An exception is thrown by using the throw keyword from inside the try block. 
Exception handlers are declared with the keyword catch, which must be placed 
immediately after the try block: */

//This function will throw an exception in case of division by zero. it will THROW it 
// to the caller of this function and the caller will have to handle it with the nearest CATCH block
double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

int main() {
    try 
	{
        double result = divide(10.0, 2.0);
        std::cout << "Result: " << result << std::endl;

        result = divide(5.0, 0.0); // This will throw an exception
        std::cout << "Result: " << result << std::endl; // This line won't be reached
    } 
	//catch (std::exception& e) is the block that will catch the exception thrown by the function.
	// The exception is caught by reference, so we can access it's members.
	//.what() is a member function of the exception class that returns a C-style character string 
	//describing the exception (in our case, the string we passed to the constructor of std::runtime_error).
	catch (const std::exception& e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

// The output of the program will be:
// Result: 5
// Exception caught: Division by zero is not allowed

// The exception thrown by the function is caught by the catch block,
// so the program continues normally after that.

/* Another example */

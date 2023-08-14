/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_overload.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:39:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/14 15:45:18 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Operator overloading allows you to provide a special meaning to an existing 
operator for user-defined data types (like classes). In simple terms, you can 
redefine or "overload" the behavior of operators for your own custom types.

For instance, C++ allows you to add two integers with the + operator. But 
what if you wanted to add two objects of a class ComplexNumber using the 
same + operator? With operator overloading, you can define this behavior. */

#include <iostream>

class ComplexNumber 
{
	private:
		float real;
		float imaginary;

	public:
		// Constructor
		ComplexNumber(float r = 0, float i = 0) : real(r), imaginary(i) {}

		// Declare the overloaded + operator function as a friend
	// Overload the + operator using a friend function
		ComplexNumber operator + (const ComplexNumber& obj) 
		{
			ComplexNumber temp;
			temp.real = real + obj.real;
			temp.imaginary = imaginary + obj.imaginary;
			return temp;
		}

		void display() {
			std::cout << real << " + i" << imaginary << std::endl;
		}
};


int main() {
    ComplexNumber c1(3, 2), c2(1, 7);
    ComplexNumber c3 = c1 + c2;
	c1.display();
	c2.display();
    c3.display(); // Outputs: 4 + i9
    return 0;
}

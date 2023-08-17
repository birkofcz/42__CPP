/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/17 14:24:47 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 
This is to define a constant number of fractional bits (how many bits are reserved 
for fractional part of the number).
 */
const int	Fixed::fractional_bits = 8;

/* 
Default constructor - cakled when a object is created. 
Gives default value to the attribute fixedpoint_value
Announce itslef for debugging purposes
 */
Fixed::Fixed()
{
	this->fixedpoint_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

/* 
Copy constructor - it is called when we're creating an object as a copy of another object.
It takes a const reference to original as argument.
It is called like so: Fixed b(a) - creates object b as a copy of a.
 */
Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->fixedpoint_value = original.getRawBits(); //this is a option here...setting it one by one...
	*this = original;
}

/* 
Assignment (=) operator overload. It returns a REFERENCE to the current object (you can work with it as it is)

Gives new meaning to the operator in a scope of our class.
It is used when a new object is created and we need to assign values to it, based on the default
values of already existing object.
Called like so:
Fixed c;	- object c created.
c = b;  	- object c is assigned the value of b. If we would do this without the definition
			  of a operator overload, the compiler will throw the datatype error, because it 
			  doesnt know what to do with (Fixed)c = (Fixed)b.

The if (this != &src) part of the code is to ensure there is no self-assignment. It is comparing
"this" (pointer to a currently active instance of the object) with &src (the memory address of the object we are sourcing).
If the addresses are the same, it is the same object. 
Self-assignment example:
Fixed x;
x = x;

return *this - could be confusing, but the function returns a reference to current object - "this" is a pointer itself,
so you are returning a dereferenced value of it.
 */
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedpoint_value  = src.fixedpoint_value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedpoint_value;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedpoint_value = raw;
}

/* EX01 part - basically the conversion of ints and floats to fixed-point value */

/* 
THEORY ON FIXED-POINT NUMBERS:
A fixed-point representation is a method of storing or representing numbers 
in non-floating-point formats.

A fixed-point number is essentially divided into two parts:
1. Integral part: The bits that represent the integer portion of the number.
2. Fractional part: The bits that represent the fraction part of the number.

The use of fixed point data type is used widely in digital signal processing (DSP) 
and game applications, where performance is sometimes more important then precision. 
Fixed point arithmetic is much faster than floating point arithmetic
 */

/* Parametric constructor taking const int - and converting it to the fixed-point value
The conversion can be done two ways:
1) I can use bitshift and literally shift the int number by fractional bits (8)
2) I can multiply the number by 2pow8, which is 256.
Example:
int x = 5;
int fixedpoint_value = 5 * 256 (or 3 << fractional_bits(8)) = 1280.
in binary: 101(5) becomes 10100000000(1280).
 */
Fixed::Fixed(const int int_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedpoint_value = int_number * 256;
}

/* Parametric constructor taking a float 
Same procedure as for the int above, but now with float
example:
3.5 -> fixedpoint_value = 3.5 * 256 -> 896. 
There is the roundf() function to round the result to the nearest integer number
*/
Fixed::Fixed(const float float_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedpoint_value = roundf(float_number * 256);
}

/* Functions that will get the float or int form the fixed-point value
It is using the same system of conversion, this time dividing fixed-point value by 256
or bitshifting >> by 8 (fractional bits).
To float - fixedpoint_value / 256, to get the float, I must cast the fixedpoint_value to float
and do the operation on it - if there is no casting, I will get int.
 */
float	Fixed::toFloat(void) const
{
	return ((float)this->fixedpoint_value / 256);
}

/* 
To int - same as above, just not casting to float - to be sure, casting to int here.
 */
int		Fixed::toInt(void) const
{
	return ((int)(this->fixedpoint_value / 256));
}

/* 
Overloading of << stream operator.
std::ostream - is the base of output stream operations. It includes cout, ofstream etc.
This overload is of that type and is used basically to tell the stream process what to print 
wehn there is instance of a class.
In this case, we need to print - when sending a Fixed object to the stream - a fixed-point number
converted to the float.
 */
std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed_object)
{
	stream << fixed_object.toFloat();
	return (stream);
}
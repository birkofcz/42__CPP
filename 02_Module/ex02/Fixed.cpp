/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/16 16:57:56 by sbenes           ###   ########.fr       */
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

Fixed::Fixed(const int int_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedpoint_value = int_number * 256;
}

Fixed::Fixed(const float float_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedpoint_value = roundf(float_number * 256);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedpoint_value / 256);
}

int		Fixed::toInt(void) const
{
	return ((int)(this->fixedpoint_value / 256));
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed_object)
{
	stream << fixed_object.toFloat();
	return (stream);
}

/* EX02 part - comparsion, arithmetic, increment & decrement overloading, min & max functions */

/* comparsion overloading = returning the logical value true-false */
bool	Fixed::operator>(const Fixed &src) 
{
	return (this->fixedpoint_value > src.fixedpoint_value);
}

bool	Fixed::operator<(const Fixed &src)
{
	return (this->fixedpoint_value < src.fixedpoint_value);
}

bool	Fixed::operator>=(const Fixed &src)
{
	return (this->fixedpoint_value >= src.fixedpoint_value);
}

bool	Fixed::operator<=(const Fixed &src)
{
	return (this->fixedpoint_value <= src.fixedpoint_value);
}

bool	Fixed::operator==(const Fixed &src)
{
	return (this->fixedpoint_value == src.fixedpoint_value);
}

bool	Fixed::operator!=(const Fixed &src)
{
	return (this->fixedpoint_value != src.fixedpoint_value);
}

/* + - * / operators - based on Fixed class */
Fixed	Fixed::operator+(Fixed &a)
{
	return (this->fixedpoint_value + a.fixedpoint_value);
}

Fixed	Fixed::operator-(Fixed &a)
{
	return (this->fixedpoint_value - a.fixedpoint_value);
}

Fixed	Fixed::operator*(Fixed &a)
{
	return (this->fixedpoint_value * a.fixedpoint_value);
}
Fixed	Fixed::operator/(Fixed &a)
{
	return (this->fixedpoint_value / a.fixedpoint_value);
}

/* Increment and decrement overloading */

/* Public static member functions min-max (non-const and const versions) */
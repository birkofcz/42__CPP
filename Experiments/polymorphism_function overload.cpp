/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism_function overload.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:30:19 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/14 14:33:56 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* Ad-hoc polymorphism / function overload
Function overloading is a C++ principle, which allows you to define many 
functions having the same name, but accepting different parameters.
It is not just for class member functions, but also works on any function. 
The principle is that you have an one-and-only function name and different 
parameters for every overload. This will allow you to specialise the process 
of a function based on its parameters */

class Sample 
{
	public:
		Sample();
		~Sample();

		void bar(char const c) const;
		void bar(int const n) const;
		void bar(float const z) const;
		void bar(Sample const & i) const;
};

Sample::Sample() {
	std::cout << "Constructor called" << std::endl;
}
Sample::~Sample() {
	std::cout << "Destructor called" << std::endl;
}

void Sample::bar(const char c) const {
	std::cout << "Member function bar called with char overload : " << c << std::endl;
}

void Sample::bar(const int n) const {
	std::cout << "Member function bar called with int overload : " << n << std::endl;
}

void Sample::bar(const float z) const {
	std::cout << "Member function bar called with float overload : " << z << std::endl;
}

void Sample::bar(const Sample & i) const {
	(void) i;
	std::cout << "Member function bar called with Sample class overload" << std::endl;
}

int main() {
	Sample sample;
	float f = 3.14;

	sample.bar(5);
	sample.bar('c');
	sample.bar(f);
	sample.bar(sample);
	return 0;
}
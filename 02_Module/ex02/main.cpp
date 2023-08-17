/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/17 17:05:28 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

/* int main() 
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */


/* My test main to test all operations */
int main()
{
	Fixed a(5.0f);
	Fixed b(10.47f);
	Fixed c(b + b);

	std::cout << "printing Fixed a in fixed-point value: " << a.getRawBits() << std::endl;
	std::cout << "Printing Fixed b(10.47f): " << b << std::endl;
	std::cout << "Printing Fixed c(b+b): " << c << std::endl;

	return 0;
}

/* Should output something like (for greater readability, the constructor/destructor mes-
sages are removed in the example below):
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016 */
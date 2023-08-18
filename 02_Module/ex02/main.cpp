/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:33:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/18 14:49:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <iomanip>

int main() 
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "Bigger a(0) or b(10.1016)?:  " << Fixed::max( a, b ) << std::endl;
	std::cout << (a <= b) << std::endl;
	return 0;
}


/* My test main to test all operations */
/* int main()
{
	Fixed a(5.0f);
	Fixed b(10.47f);
	Fixed c(b + b);

	std::cout << "printing Fixed a in fixed-point value: " << a.getRawBits() << std::endl;
	std::cout << "Printing Fixed b(10.47f): " << b << std::endl;
	std::cout << "Printing Fixed c(b+b): " << c << std::endl;
	std::cout << "Printing c - a: " << c - a << std::endl;
	std::cout << "Printing c * a: " << c * a << std::endl;
	std::cout << "Printing c / a: " << c / a << std::endl;
	std::cout << "Printing ++a: " << ++a << std::endl;
	std::cout << "Printing a++: " << a++ << std::endl;
	std::cout << "Now printing a: " << a << std::endl;
	return 0;
} */

/* 
Illustrative main for the phenomenon of floating point precision error:
*/
/* int main() {
    float sum = 0.0f;
    float smallValue = 1.001f;
    int iterations = 10000000; // 10 million

    for (int i = 0; i < iterations; i++) {
        sum += smallValue;
    }

    // Expected result is iterations * smallValue
    float expected = iterations * smallValue;

    std::cout << std::setprecision(8) << "After adding " << smallValue << " for " 
              << iterations << " times, the sum is: " << sum << std::endl;
    std::cout << "Expected result: " << expected << std::endl;
    std::cout << "Error: " << sum - expected << std::endl;

    return 0;
} */



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
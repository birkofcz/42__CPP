/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:31:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/14 11:41:14 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	this->fixedpoint_value = 0;
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
	std::cout << "Copy Assignment Constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixedpoint_value  = src.getRawBits();
	std::cout << "Copy Assignment Constructor called" << std::endl;
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

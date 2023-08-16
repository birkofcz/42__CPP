/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:57:17 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/16 14:55:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
/* 
ORTHODOX CANONICAL FORM:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
Split your class code into two files. The header file (.hpp/.h) contains the class
definition whereas the source file (.cpp) contains the implementation.
 */

class Fixed
{
	private:
		int					fixedpoint_value;
		static const int	fractional_bits;

	public:
	
		Fixed();
		Fixed(const int int_num);				//ex01 - constructor taking int
		Fixed(const float float_num);			//ex01 - constructor taking float
		Fixed(const Fixed& original);			//ex 00 - Copy constructor
		Fixed &operator=(const Fixed& src);		//ex 00 - Copy assignment operator overload
		~Fixed(); 
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &f);

#endif

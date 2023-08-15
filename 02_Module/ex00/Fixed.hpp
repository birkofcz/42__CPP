/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:57:17 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/15 14:54:15 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
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
		Fixed(const Fixed& copy);				//Copy constructor
		Fixed &operator = (const Fixed& src);	//Copy assignment operator overload
		~Fixed(); 
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
};

#endif

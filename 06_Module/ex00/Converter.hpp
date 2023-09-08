/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:38:35 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 14:35:17 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
#include <sstream>

enum e_type
{
	CHAR	= 0,
	INT		= 1,
	FLOAT	= 2,
	DOUBLE	= 3
};

class ScalarConverter
{
	private:
		static bool		_type;

		ScalarConverter();
		ScalarConverter(ScalarConverter const& original);
		ScalarConverter& operator=(ScalarConverter const& src);
		~ScalarConverter();

	public:
		static void		convert(std::string str);
		static void 	identify(std::string str);
};

#endif
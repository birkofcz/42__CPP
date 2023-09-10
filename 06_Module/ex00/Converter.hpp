/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:38:35 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/10 11:18:28 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>
# include <iomanip>
//# include <fstream> 
#include <typeinfo>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

enum e_type
{
	CHAR	= 0,
	INT		= 1,
	FLOAT	= 2,
	DOUBLE	= 3,
	INVALID	= 4
};

class ScalarConverter
{
	private:
		static int		_type;

		ScalarConverter();
		ScalarConverter(ScalarConverter const& original);
		ScalarConverter& operator=(ScalarConverter const& src);
		~ScalarConverter();

	public:
		static void		convert(std::string str);
		static void 	identify(std::string str);
		static int 		getType();	
		static void		setType(int type);
		static void		Checker(std::string str);
};

#endif
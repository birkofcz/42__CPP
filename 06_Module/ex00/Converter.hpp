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

/* Theory of casting in C++:

C-style cast - compile time casting, no runtime checks. Used for implicit conversions. Generally unsafe.
example: (int)3.14 - converts double to int, (double)3 - converts int to double

static_cast - compile time casting, no runtime checks. Used for implicit conversions. Generally safe.
examples: static_cast<int>(3.14) - converts double to int, static_cast<double>(3) - converts int to double
Used over the C-style cast because it is more restrictive and EASIER to find in the code.

dynamic_cast - runtime casting, checks if the cast is possible. Used for downcasting in inheritance. Generally safe.
example: dynamic_cast<Derived*>(base_ptr) - converts base class pointer to derived class pointer.
tech behind it: dynamic_cast uses RTTI (Run Time Type Information) to check if the cast is possible.
RTTI is a mechanism that stores type information at runtime. It is used by dynamic_cast, typeid and type_info.

const_cast - compile time casting, no runtime checks. Used to cast away constness. Generally unsafe.
example: const_cast<char*>(str.c_str()) - converts const char* to char*.
Used to cast away constness, but it is undefined behavior to modify a const object.
tech behind it: const_cast simply tells the compiler to treat the pointer as if it were pointing to a different type.

reinterpret_cast - compile time casting, no runtime checks. Used to cast between unrelated types. Generally unsafe. 
example: reinterpret_cast<int>(str.c_str()) - converts const char* to int. Or with structures: reinterpret_cast<struct*>(str.c_str()) - converts const char* to struct*.
Used to cast between unrelated types, but is not safe to use in most cases. Used for serialization, signal handling, etc.
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted 
across a network connection link to be reconstructed later in the same or another computer environment.
tech behind it: reinterpret_cast simply tells the compiler to treat the pointer as if it were pointing to a different type.
It is a low-level operation that is not intended to be used in general programming, but can be necessary for some low-level tasks.
*/
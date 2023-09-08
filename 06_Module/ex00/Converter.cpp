/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:00:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 15:15:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* OCC */
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const& original)
{
	*this = original;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter(){}


/* Data members*/
//this holds flags for each type, to indicate what was  sent as parameter 
//(index 0 = char, 1 = int, 2 = float, 3 = double) - connected to enum e_type
/* bool	ScalarConverter::_flags[4] = {false, false, false, false}; */

/* METHODS */

void ScalarConverter::identify(std::string input)
{
	std::stringstream ss;
	int integer;
	
	if ((ss >> integer).fail())
	{
		if (input.find(".") && input.find("f"))
			_type = FLOAT;
		else if (input.find(".") && !input.find("f") && !input.length() > 1)
			_type = DOUBLE;
		else if (input.length() == 1 && std::isprint(input[0]) && std::isalpha(input[0]))
			_type = CHAR;
		else
			throw std::invalid_argument("Unrecognizable type");
	}
	else
		_type = INT;

}

void ScalarConverter::convert(std::string input)
{
	
	
}
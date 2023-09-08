/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:00:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/08 16:20:09 by sbenes           ###   ########.fr       */
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
/* 	std::stringstream ss;
	int integer; */
	int i = 0;

	if (input.length() == 1 && std::isalpha(input[0]) && std::isprint(input[0]))
		_type = CHAR;
	else
	{
		while (input[i])
		{
			if (std::isdigit(input[i]))
				i++;
			if (input[i] == '.' && std::isdigit(input[i + 1]))
			{
				i++;
				while (std::isdigit(input[i]))
				{
					i++;
					if(input[i] == 'f' && !input[i + 1])
						_type = FLOAT;
				}
				if (!input[i])
					_type = DOUBLE;
			}
			if (!input[i])
				_type = INT;
		}
	}
}

	/* first version
	if ((ss >> integer).fail())
	{
		if (std::isdigit(input[0]) && input.find(".") && input.find("f"))
			_type = FLOAT;
		else if (std::isdigit(input[0]) && input.find(".") && !input.find("f") && !input.length() > 1)
			_type = DOUBLE;
		else if (input.length() == 1 && std::isprint(input[0]) && std::isalpha(input[0]))
			_type = CHAR;
		else
			throw std::invalid_argument("Unrecognizable type");
	}
	else
		_type = INT; */

void ScalarConverter::convert(std::string input)
{
	identify(input);
	switch(_type)
	{
		case CHAR:
			std::cout << "char: " << input[0] << std::endl;
			std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
			std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
			break;
		case INT:
			std::cout << "char: " << static_cast<char>(std::stoi(input)) << std::endl;
			std::cout << "int: " << std::stoi(input) << std::endl;
			std::cout << "float: " << static_cast<float>(std::stoi(input)) << std::endl;
			std::cout << "double: " << static_cast<double>(std::stoi(input)) << std::endl;
			break;
		case FLOAT:
			std::cout << "char: " << static_cast<char>(std::stof(input)) << std::endl;
			std::cout << "int: " << static_cast<int>(std::stof(input)) << std::endl;
			std::cout << "float: " << std::stof(input) << std::endl;
			std::cout << "double: " << static_cast<double>(std::stof(input)) << std::endl;
			break;
		case DOUBLE:
			std::cout << "char: " << static_cast<char>(std::stod(input)) << std::endl;
			std::cout << "int: " << static_cast<int>(std::stod(input)) << std::endl;
			std::cout << "float: " << static_cast<float>(std::stod(input)) << std::endl;
			std::cout << "double: " << std::stod(input) << std::endl;
			break;
		default:
			throw std::invalid_argument("Unrecognizable type");
	}
}
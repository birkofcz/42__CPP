/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:00:29 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/10 12:02:37 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* OCC */
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &original)
{
	*this = original;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/* Data members*/
// this holds flags for each type, to indicate what was  sent as parameter
//(index 0 = char, 1 = int, 2 = float, 3 = double) - connected to enum e_type
/* bool	ScalarConverter::_flags[4] = {false, false, false, false}; */

/* Data members */
// setting the type of the parameter to default value, needs to be done because of static data member
int ScalarConverter::_type = -1;

/* METHODS - Getters & setter*/
int ScalarConverter::getType()
{
	return _type;
}

void ScalarConverter::setType(int type)
{
	_type = type;
}

/* METHODS - identify & convert */
void ScalarConverter::identify(std::string input)
{
	bool hasDecimal = false;
	bool hasF = false;
	// If the input is infinities or nan:
	if (input == "nan" || input == "-inf" || input == "+inf")
	{
		setType(DOUBLE);
		return;
	}	
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		setType(FLOAT);
		return;
	}
	// If the input is a single printable alphabet character
	if (input.length() == 1 && std::isalpha(input[0]) && std::isprint(input[0]))
	{
		setType(CHAR);
		return;
	}
	// Check if the input starts with '-' and remove it
	if (input.length() > 0 && input[0] == '-')
		input.erase(input.begin());
	for (std::string::size_type i = 0; i < input.size(); ++i)
	{
		char c = input[i];
		if (std::isdigit(c))
			continue;
		else if (c == '.' && !hasDecimal)
			hasDecimal = true;
		else if (c == 'f' && !hasF)
			hasF = true;
		else
		{
			setType(INVALID);
			return;
		}
	}
	if (hasDecimal)
	{
		if (hasF)
			setType(FLOAT);
		else
			setType(DOUBLE);
	}
	else
		setType(INT);
}

//Conversion functions - identifies the type of the input and converts it to the other types, using the appropriate type for itself.
void ScalarConverter::convert(std::string input)
{
	identify(input);
	int type = getType();
	if (type == FLOAT) // If the type is float, remove the 'f' at the end, so we cabn take advantage of the stringstream (that can evaluate nan and inf)
		input.erase(input.size() - 1);
	std::istringstream ss(input); // Create a stringstream with the input - is used for conversion of the type itself.	std::cout << std::fixed << std::setprecision(1);
	std::cout << std::fixed << std::setprecision(1);
	switch (type)
	{
		case CHAR:
		{
			std::cout << "char: " << input[0] << std::endl;
			std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
			break;
		}
		case INT:
		{
			int value;
			ss >> value;

			if (value >= 0 && value <= 31)
				std::cout << "char: " << "Non displayable" << std::endl;
			else if (value < 0 || value > 127)
				std::cout << "char: " << "imposible" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(value) << std::endl;
			if (value > 2147483647 || value < -2147483648)
				std::cout << "int: " << "imposible" << std::endl;
			else
				std::cout << "int: " << value << std::endl;
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value) << std::endl;
			break;
		}
		case FLOAT:
		{
			float value;
			ss >> value;
			if (std::isnan(value) || std::isinf(value))
				std::cout << "char: " << "imposible" << std::endl;
			else if (!std::isprint(value))
				std::cout << "char: " << "Non displayable" << std::endl;
			else if (value < 0 || value > 127)
				std::cout << "char: " << "imposible" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(value) << std::endl;
			if (std::isnan(value) || std::isinf(value))
				std::cout << "int: " << "imposible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << value << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value) << std::endl;

			break;
		}
		case DOUBLE:
		{
			double value;
			ss >> value;
			if (std::isnan(value) || std::isinf(value))
				std::cout << "char: " << "imposible" << std::endl;
			else if (!std::isprint(value))
				std::cout << "char: " << "Non displayable" << std::endl;
			else if (value < 0 || value > 127)
				std::cout << "char: " << "imposible" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(value) << std::endl;
			if (std::isnan(value) || std::isinf(value))	
				std::cout << "int: " << "imposible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
			std::cout << "double: " << value << std::endl;	
			break;
		}
		default:
		{
			throw std::invalid_argument(RED "Unrecognizable type" RES);
		}
	}
}

//Checker function - does the same as convert, but adding the type of the variable to the output using typeid
void ScalarConverter::Checker(std::string input) {
    identify(input);
    int type = getType();

    if (type == FLOAT) 
        input.erase(input.size() - 1);

    std::istringstream ss(input); // Create a stringstream with the input
    std::cout << std::fixed << std::setprecision(1);

    std::cout << std::endl << YEL << "enum table: " << RES << std::endl;
    std::cout << "CHAR: " << CHAR << std::endl;
    std::cout << "INT: " << INT << std::endl;
    std::cout << "FLOAT: " << FLOAT << std::endl;
    std::cout << "DOUBLE: " << DOUBLE << std::endl;
    std::cout << "INVALID: " << INVALID << std::endl << std::endl;
    std::cout << YEL << "Datatype after casting check (using \"typeid().name()\" operator) :" << RES << std::endl;

    switch (type) {
        case CHAR:
        {
			std::cout << "datatype identified: CHAR" << std::endl;
            std::cout << "Datatype value in enum: " << type << std::endl;
            char value = input[0];
            std::cout << "char: " << value << " [" << typeid(value).name() << "]" << std::endl;
            std::cout << "int: " << static_cast<int>(value) << " [" << typeid(static_cast<int>(value)).name() << "]" << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << " [" << typeid(static_cast<float>(value)).name() << "]" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << " [" << typeid(static_cast<double>(value)).name() << "]" << std::endl;
            break;
        }
        case INT:
        {
            int value;
            ss >> value;
			std::cout << "datatype identified: INT" << std::endl;
            std::cout << "Datatype value in enum: " << type << std::endl;
            if (value >= 0 && value <= 31)
                std::cout << "char: " << "Non displayable" << std::endl;
            else if (value < 0 || value > 127)
                std::cout << "char: " << "impossible" << std::endl;
            else
                std::cout << "char: " << static_cast<char>(value) << " [" << typeid(static_cast<char>(value)).name() << "]" << std::endl;
            if (value > 2147483647 || value < -2147483648)
                std::cout << "int: " << "impossible" << std::endl;
            else
                std::cout << "int: " << value << " [" << typeid(value).name() << "]" << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << " [" << typeid(static_cast<float>(value)).name() << "]" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << " [" << typeid(static_cast<double>(value)).name() << "]" << std::endl;
            break;
        }
        case FLOAT:
        {
            float value;
            ss >> value;
			std::cout << "datatype identified: FLOAT" << std::endl;
            std::cout << "Datatype value in enum: " << type << std::endl;
            if (std::isnan(value) || std::isinf(value))
                std::cout << "char: " << "impossible" << std::endl;
            else if (!std::isprint(value))
                std::cout << "char: " << "Non displayable" << std::endl;
            else if (value < 0 || value > 127)
                std::cout << "char: " << "impossible" << std::endl;
            else
                std::cout << "char: " << static_cast<char>(value) << " [" << typeid(static_cast<char>(value)).name() << "]" << std::endl;
            if (std::isnan(value) || std::isinf(value))
                std::cout << "int: " << "impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(value) << " [" << typeid(static_cast<int>(value)).name() << "]" << std::endl;
            std::cout << "float: " << value << "f" << " [" << typeid(value).name() << "]" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << " [" << typeid(static_cast<double>(value)).name() << "]" << std::endl;
            break;
        }
        case DOUBLE:
        {
            double value;
            ss >> value;
			std::cout << "datatype identified: DOUBLE" << std::endl;
            std::cout << "Datatype value in enum: " << type << std::endl;
            if (std::isnan(value) || std::isinf(value))
                std::cout << "char: " << "impossible" << std::endl;
            else if (!std::isprint(value))
                std::cout << "char: " << "Non displayable" << std::endl;
            else if (value < 0 || value > 127)
                std::cout << "char: " << "impossible" << std::endl;
            else
                std::cout << "char: " << static_cast<char>(value) << " [" << typeid(static_cast<char>(value)).name() << "]" << std::endl;
            if (std::isnan(value) || std::isinf(value))
                std::cout << "int: " << "impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(value) << " [" << typeid(static_cast<int>(value)).name() << "]" << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << " [" << typeid(static_cast<float>(value)).name() << "]" << std::endl;
            std::cout << "double: " << value << " [" << typeid(value).name() << "]" << std::endl;
            break;
        }
        default:
        {
			std::cout << "datatype identified: INVALID" << std::endl;
			std::cout << "Datatype value in enum: " << type << std::endl;
            throw std::invalid_argument(RED "Unrecognizable type" RES);
        }
    }
}

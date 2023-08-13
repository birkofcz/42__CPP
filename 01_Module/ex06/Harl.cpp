/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:50:33 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 14:41:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* Constructor */
Harl::Harl(){};

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << YEL << DEBUG_M << RES << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << YEL << INFO_M << RES << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << YEL << WARNING_M << RES << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << RED << ERROR_M << RES << std::endl;
}

/* For comparation purposes */
static std::string sb_tolower_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]);
	return result;
}

/* Because swith control structure cannot take strings, must be int.
Also - it is defined so it takes the REFERENCE  to std::string argument. 
Working with reference is better for performance(not making a copy), also you 
are guaranted to not modify original arg(passing a memory address) */
int Harl::ft_setlevel(std::string& level)
{
	if (level == "DEBUG" || level == sb_tolower_str("DEBUG")) return DEBUG;
	else if (level == "INFO" || level == sb_tolower_str("INFO")) return INFO;
	else if (level == "WARNING" || level == sb_tolower_str("WARNING")) return WARNING;
	else if (level == "ERROR" || level == sb_tolower_str("ERROR")) return ERROR;
	else 
		return -1;
}

/* 
This function creates the array of pointer to member functions of Harl class.
This is a typedef declared in the header as "typedef void(Harl::*mem_func)(void)"
Becouse we dont have object instance here, we call those functions as follows:
this->*func[index], whes "this->" ("this instatnce") works the same as for example:
Harl harl;
harl->*func[index].

FALL-THROUGH BEHAVIOR for switch statement. For this version of Harl, we need him to 
shout the complain of passed argument, and also all of the subsequent cases. This is done by 
not adding a "break" statement to the cases (except for the last one - to break out of the loop").
 */
void Harl::complain(std::string level)
{
	int level_n = ft_setlevel(level);
	mem_func functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (level_n)
	{
		case DEBUG:
			(this->*functions[DEBUG])();
		case INFO:
			(this->*functions[INFO])();
		case WARNING:
			(this->*functions[WARNING])();
		case ERROR:
			(this->*functions[ERROR])();
			break ;
		default:
			std::cerr << YEL << STANDARD_M << RES << std::endl;
	}
}

/* Destructor */
Harl::~Harl(){};

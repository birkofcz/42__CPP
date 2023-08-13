/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:50:33 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 12:05:59 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << YEL << DEBUG << RES << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << YEL << INFO << RES << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << YEL << WARNING << RES << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << RED << ERROR << RES << std::endl;
}
static std::string sb_tolower_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]);
	return result;
}

/* Because swith control structure cannot take strings, must be int */
int Harl::ft_setlevel(std::string& level)
{
	if (level == "DEBUG" || level == sb_tolower_str("DEBUG")) return 0;
	else if (level == "INFO" || level == sb_tolower_str("INFO")) return 1;
	else if (level == "WARNING" || level == sb_tolower_str("WARNING")) return 2;
	else if (level == "ERROR" || level == sb_tolower_str("ERROR")) return 3;
	else 
		return -1;
}
void Harl::complain(std::string level)
{
	int level_n = ft_setlevel(level);

	switch (level_n) 
	{
		case 0:
			this->debug();
			break ;
		case 1:
			this->info();
			break ;
		case 2:
			this->warning();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cerr << YEL << STANDARD << RES << std::endl;
	}
}

Harl::~Harl(){};

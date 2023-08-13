/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:23:48 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 13:55:15 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	
	if (ac < 2)	return ((std::cerr << RED << NO_ARGS_M << RES << std::endl), 1);
	else if (ac > 2) return ((std::cerr << RED << TOO_MUCH_ARGS_M << RES << std::endl), 1);
	else harl.complain(av[1]);
	return 0;
}
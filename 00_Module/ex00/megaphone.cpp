/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:28:03 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/10 16:11:13 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void ft_megaphone(std::string src)
{
	int i = -1;
	
	while (src[++i])
	{
		src[i] = toupper(src[i]);
		std::cout << src[i];
	}
}

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		while (av[++i])
			ft_megaphone(av[i]);
	}
	return 0;
}


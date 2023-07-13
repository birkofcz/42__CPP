/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:28:03 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/13 14:52:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using namespace std;

class MegaPhone
{
public:

	void ft_megaphone(string src)
	{
		int i = -1;

		while (src[++i])
		{
			src[i] = toupper(src[i]);
			cout << src[i];
		}
	}
};

int main(int ac, char **av)
{
	MegaPhone megaphone;
	int i = 0;

	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else if (ac > 1)
	{
		while (av[++i])
			megaphone.ft_megaphone(av[i]);

	}
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:42:07 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 15:00:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"
#include <ctime>

int main()
{
	//need to plant a seed for the random number generator - less 
	//likely to get the same number generated every time.
	srand(static_cast<unsigned>(time(NULL)));

	std::cout << std::endl;
	std::cout << YEL << "Generating three random classes:" << RES << std::endl;
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();


	std::cout << std::endl;
	std::cout << YEL << "First identification:" << RES << std::endl;
	identifyFromPtr(base1);
	identifyFromRef(*base1);

	std::cout << std::endl;
	std::cout << YEL << "Second identification:" << RES << std::endl;
	identifyFromPtr(base2);
	identifyFromRef(*base2);

	std::cout << std::endl;
	std::cout << YEL << "Third identification:" << RES << std::endl;
	identifyFromPtr(base3);
	identifyFromRef(*base3);

	std::cout << std::endl;

	delete base1;
	delete base2;
	delete base3;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/04 11:18:27 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bure1("Pitomec", 150);

	std::cout << std::endl;
	std::cout << bure1 << std::endl;
	bure1.gradeUp(1);
	std::cout << bure1 << std::endl;

	
	return 0;
}
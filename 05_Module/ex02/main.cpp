/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:18:06 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/07 11:41:54 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("pitomec", 10);
		ShrubberyCreationForm f1("home");
		
		std::cout << f1 << std::endl;
		//b1.signForm(f1);
		b1.executeForm(f1);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return 0;
}
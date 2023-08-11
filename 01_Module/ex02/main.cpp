/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:31:39 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 13:22:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Theory */
/* References are aliases for existing variables. 
It is a pointer that is constant and always dereferenced and never void */

#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

int	main()
{
	std::cout << "\n" << RED << "VARIABLES " << RES << "& " << GRE << "POINTERS " << RES << "& " << YEL << "REFERENCES" << RES << ":" << std::endl;
	std::string brain = "HI THIS IS BRAIN";

	std::cout <<"\nstd::string " << RED << "brain " << RES << "= \"HI THIS IS BRAIN\";" << std::endl;
	
	std::string *stringPTR = &brain;
	std::cout << "std::string "<< GRE << "*stringPTR" << RES << "= &brain;" << std::endl;

	std::string &stringREF = brain;
	std::cout << "std::string "<< YEL << "&stringREF" << RES << "= brain;" << std::endl;


	std::cout << "\nMemory address of \"brain\" " << RED << "variable (&brain): " << RES << "\t\t" << RED << &brain << RES << std::endl;
	std::cout << "Memory address held by " << GRE << "stringPTR (stringPTR): " << RES << "\t\t" << RED << stringPTR << RES << std::endl;
	std::cout << "Memory address of the " << GRE << "stringPTR itself (&stringPTR): " << RES << "\t" << GRE << &stringPTR << RES << std::endl; 
	std::cout << "Memory address held by " << YEL << "stringREF (&stringREF): " << RES << "\t\t" << RED << &stringREF << RES << std::endl << std::endl;

	std::cout << "The value of \"brain\" " << RED << "variable (brain): " << RES << brain << std::endl;
	std::cout << "The value pointed to by " << GRE << "stringPTR (*stringPTR): " << RES << *stringPTR << std::endl;
	std::cout << "The value pointed to by " << YEL << "stringREF (stringREF): " << RES << stringREF << std::endl << std::endl;

	return 0;

}
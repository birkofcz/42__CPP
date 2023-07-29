/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_alloc.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:48:13 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/29 17:11:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* Dynamic allocation in C++ */

/* Dynamicka alokace nam umoznuje vytvaret promenne ne na zaklade deklarace, 
ale podle potreby programu
Experiment with valgrind ./a.out to see what is going on with or without delete statement.
 */

int main()
{
	std::string *name = new std::string; //"new is used to dyamically alloc memory space"
	
	std::cout << std::endl;

	std::cout << "[[ DYNAMIC MEMORY ALLOCATION ]]" << std::endl;
	std::cout << std::endl;
	std::cout << "std::string *name = new std::string;" << std::endl << std::endl;

	*name = "Alice";
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << " is " << name->length() << " chars long." << std::endl;
	
	
	*name = "EleanorTheThird";
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << " is " << name->length() << " chars long." << std::endl;

	delete name; // frees the memory
	name = nullptr;
	std::cout << "Address of the poiter 'name' to dynamic memory: " << name << std::endl;
	std::cout << "Saved name: " << *name << std::endl << std::endl; //here will be segfault;

	return 0;	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_function.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:19:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/23 16:04:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

/* 
Trim function to trim the whitespace from the start and end of the string
 */

std::string ft_trimSpace(std::string& src)
{
	std::string::iterator front_it  = src.begin();
	std::string::iterator back_it = src.end(); 
	
	
	
	while (front_it != src.end() && std::isspace(*front_it))
		++front_it;

	//*(back_it - 1) is the position of the last char, src.end() is poiting to
	// the position right next to the last char.
	while (back_it != front_it && std::isspace(*(back_it - 1)))
		--back_it;

	return std::string(front_it, back_it);
}

/* Trim front of specified char */
std::string ft_trimFront(std::string& src, char to_trim)
{
	std::string::iterator front_it  = src.begin();
	std::string::iterator back_it = src.end(); 
	
	while (front_it != src.end() && *front_it == to_trim)
		++front_it;

	return std::string(front_it, back_it);
}

/* Trims back of specified char */
std::string ft_trimBack(std::string& src, char to_trim)
{
	std::string::iterator front_it  = src.begin();
	std::string::iterator back_it = src.end(); 
	
	while (back_it != front_it && *(back_it - 1) == to_trim)
		--back_it;

	return std::string(front_it, back_it);
}

int main()
{
	std::string original = "  not trimmed   ";
	std::string original2 = "not trimmed";

	std::string trimmed = ft_trimSpace(original);
	std::string trimmed2 = ft_trimBack(original2, 'd');

	std::cout << "Original: |" << original << "| of length: " << original.length() << std::endl;
	std::cout << "Trimmed: |" << trimmed << "| of length: " << trimmed.length() << std::endl;
	std::cout << std::endl;
	std::cout << "Original2: |" << original2 << "| of length: " << original2.length() << std::endl;
	std::cout << "Trimmed2: |" << trimmed2 << "| of length: " << trimmed2.length() << std::endl;
	
	return 0;
}
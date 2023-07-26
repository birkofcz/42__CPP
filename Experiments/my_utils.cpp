/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:07:45 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Utility function written for C++ usage*/

#include <iostream>
#include <string>

/* SB_TOLOWER_STR - lowercases the whole string passed as param. To speed up string 
comparation process*/
std::string sb_tolower_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]); //we need to (and CAN do it!) append each character to result string. There is no need to dynamically allocate mem.
	return result;
}
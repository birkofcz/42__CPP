/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_split.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:15:30 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 16:54:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"


int word_count(const std::string& source, char c) 
{
	unsigned long word_num = 0;
	unsigned long pos = 0;

	while (pos < source.size()) 
	{
		if (source[pos] != c) 
		{
			word_num += 1;	
			pos = source.find(c, pos);
			if (pos == std::string::npos) break;
		}
		pos += 1;
	}
	return word_num;
}

static std::string* ft_insert_string(std::string* result, const std::string& s, char c) 
{
	unsigned long i = 0;
	unsigned long start = 0;
	unsigned long end = s.find(c);

	while (end != std::string::npos) 
	{
		result[i] = s.substr(start, end - start);
		i += 1;
		start = end + 1;
		end = s.find(c, start);
	}
	result[i] = s.substr(start);
	return result;
}


std::string* sb_split(const std::string& source, char delimiter) 
{
	unsigned long word_num = word_count(source, delimiter);
	std::string* result = new std::string[word_num];
	return ft_insert_string(result, source, delimiter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:58:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/11 16:54:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

#include <iostream>
#include <fstream>


/* replacer.cpp */
std::string *sb_split(const std::string& source, char delimiter);
int word_count(const std::string& source, char c);

#endif
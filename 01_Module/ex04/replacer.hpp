/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:58:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/12 16:03:32 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

/* main.cpp */
void	ft_replacer(char **av);
void	ft_testprint(std::string infile, std::string find, std::string replace_with, std::string outfile);

#endif
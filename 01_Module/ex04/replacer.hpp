/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:58:59 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/12 15:51:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

#include <iostream>
#include <fstream>

/* main.cpp */
void	ft_replacer(char **av);
void	ft_testprint(std::string infile, std::string find, std::string replace_with, std::string outfile);

#endif
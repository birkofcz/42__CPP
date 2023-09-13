/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:26:41 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/13 15:38:47 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <string>

/* Colors */
# define GRE "\033[32m"
# define RED "\033[31m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

/* Enumerators */
enum e_type
{
	CHAR	= 0,
	INT		= 1,
	FLOAT	= 2,
	DOUBLE	= 3,
	INVALID	= 4
};

/* Functions templates */
template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b)
{
	return (a < b)? a : b;
}

template <typename T>
T max(T a, T b)
{
	return (a > b)? a : b;
}

/* Functions */
int identify(char* str);


#endif

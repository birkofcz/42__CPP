/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:26:41 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/15 10:41:11 by sbenes           ###   ########.fr       */
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


//Templates theory
//https://www.learncpp.com/cpp-tutorial/function-templates/
//https://www.learncpp.com/cpp-tutorial/template-classes/
/* 
Templates   allows functions and classes to operate with generic types. 
This allows a function or class to work on many different data types without being
rewritten for each one.

template <typename T>
T max(T a, T b)
{
	return (a > b)? a : b;
}
Instantiating a template
When the compiler sees this function template, it doesn’t generate any code. Instead, it
waits until you use the template, and then it generates code for that specific type.
example:
max<int>(3, 7);
generate this:
int max(int a, int b)
{
	return (a > b)? a : b;
}
and:

max<float>(3.0f, 7.0f);
generates this:
float max(float a, float b)
{
	return (a > b)? a : b;
}
etc...

This is called template instantiation. The compiler generates a new function for each
type you use with the template. This is why templates are sometimes called parameterized
types: the type is a parameter to the template.

Class templates
You can also create class templates. The syntax is similar to function templates, except
that you must use the keyword class instead of typename: template <class T>
*/
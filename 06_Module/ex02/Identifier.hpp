/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:42:38 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 14:51:09 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

# define RED "\033[31m"
# define GRE "\033[32m"   
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

// Base class
class Base
{
	public:
		virtual ~Base();
};

// Adjacent classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identifyFromPtr(Base* base);
void identifyFromRef(Base& base);

#endif



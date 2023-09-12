/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:42:38 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 11:45:04 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

# include <iostream>
# include <string>

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
void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

#endif



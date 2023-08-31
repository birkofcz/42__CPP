/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 13:10:40 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Animal
{
	protected:
		std::string	_type;
		
	public:
		virtual void		makeSound() const;			// virtual makes it possible to override this method in derived classes
		virtual std::string	getType() const;		// virtual makes it possible to override this method in derived classes
		
		Animal();
		Animal(std::string type);
		Animal(const Animal& original);
		Animal &operator=(const Animal& src);
		virtual ~Animal();							// virtual makes it possible to call derived class destructor when deleting base class pointer
};

#endif
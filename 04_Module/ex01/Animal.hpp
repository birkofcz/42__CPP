/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 17:46:30 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Animal
{
	protected:
		std::string	_type;
		
	public:
		virtual void	makeSound() const;
		virtual void	readBrain(std::string name) const;
		virtual std::string	getType() const;
		
		Animal();
		Animal(const Animal& original);
		Animal &operator=(const Animal& src);
		virtual ~Animal();
};

#endif
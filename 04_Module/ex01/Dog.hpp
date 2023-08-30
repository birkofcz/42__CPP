/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 13:42:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		void	makeSound() const;
		void	readBrain(std::string name) const;

		Dog();
		Dog(const Dog& original);
		Dog &operator=(const Dog& src);
		~Dog();
};

#endif
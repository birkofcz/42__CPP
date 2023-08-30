/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 13:42:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"
/* ..so you dont have to write this all over again.. */

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		void	makeSound() const;
		void	readBrain(std::string name) const;

		Cat();
		Cat(const Cat& original);
		Cat &operator=(const Cat& src);
		~Cat();
};

#endif
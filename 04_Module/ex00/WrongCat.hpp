/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/29 13:42:22 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"
/* ..so you dont have to write this all over again.. */

class WrongCat : public WrongAnimal
{
	public:
		void	makeSound() const;

		WrongCat();
		WrongCat(const WrongCat& original);
		WrongCat &operator=(const WrongCat& src);
		~WrongCat();
};

#endif
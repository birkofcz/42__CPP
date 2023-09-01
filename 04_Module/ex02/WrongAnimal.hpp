/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:57:27 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 11:18:09 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class WrongAnimal
{
	protected:
		std::string	_type;
		
	public:
		void	makeSound() const;
		virtual std::string	getType() const;
		
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& original);
		WrongAnimal &operator=(const WrongAnimal& src);
		virtual ~WrongAnimal();
};

#endif
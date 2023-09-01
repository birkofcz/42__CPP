/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 14:35:21 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class AAnimal
{
	protected:
		std::string	_type;
		
	public:
		virtual void		makeSound() const = 0;	// pure virtual method makes this class abstract - cannot be instantiated
		virtual std::string	getType() const;		// virtual makes it possible to override this method in derived classes
		virtual void 		readBrain() const;
		
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& original);
		AAnimal &operator=(const AAnimal& src);
		virtual ~AAnimal();							// virtual makes it possible to call derived class destructor when deleting base class pointer
};

#endif
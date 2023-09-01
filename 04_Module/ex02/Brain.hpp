/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:34:25 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/01 11:44:38 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

class Brain
{
	protected:
		std::string	*_ideas;
		
	public:
		std::string	*getIdeas() const;
		std::string *setIdeas();
		
		Brain();
		Brain(std::string type);
		Brain(const Brain& original);
		Brain &operator=(const Brain& src);
		virtual ~Brain();							// virtual makes it possible to call derived class destructor when deleting base class pointer
};

#endif
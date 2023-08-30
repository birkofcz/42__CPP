/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:59:36 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/30 16:44:16 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
	protected:
		std::string	*_ideas;
	
	public:

		std::string *getIdeas();
		
		Brain();
		Brain(const Brain& original);
		Brain &operator=(const Brain& src);
		~Brain();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:37:40 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/31 12:38:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
	public:
		// methods
		void	highFiveGuys();

		//my additional methods for testing purposes
		void	report() const;
		// Constructors
		FragTrap();
		FragTrap(std::string trap_name);
		FragTrap(const FragTrap &original);
		FragTrap & operator=(const FragTrap &src);
		~FragTrap();	
};

#endif
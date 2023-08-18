/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:34 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/18 17:26:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

typedef std::string str;
auto& out = std::cout;
auto& nl = std::endl<char, std::char_traits<char>>;


class ClapTrap
{
	private: // or protected fo inheritance?

	public:
	
	ClapTrap(str name);
};

#endif
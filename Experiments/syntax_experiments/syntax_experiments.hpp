/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_experiments.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:45:48 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/28 15:52:44 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Warlock
{
	private:
		std::string		_name;
		std::string		_title;
		
		Warlock();
		Warlock(const Warlock&);
		Warlock& operator=(const Warlock&);
		
	public:
		Warlock(std::string const&, std::string const&);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void	setTitle(const std::string&);

		void	introduce() const;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:46:09 by sbenes            #+#    #+#             */
/*   Updated: 2023/08/13 12:07:46 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YEL "\033[33m"
#define RES "\033[0m"

#define DEBUG "HARL: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO "HARL: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING "HARL: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
#define ERROR "HARL:This is unacceptable! I want to speak to the manager now."
#define STANDARD "[ Probably complaining about random insignificat problem ... ]"
#define NO_ARGS "HARL: eee...don't know what to complain about right now, but I'm sure I'll find something soon!"
#define TOO_MUCH_ARGS "HARL: Wooow, take it easy, my complains are so important that I make sure I do one at a time!"


class Harl
{	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);
		int		ft_setlevel(std::string& level);
		
	Harl();
	~Harl();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/26 17:13:39 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string sb_tolower_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]);
	return result;
}

void	ft_homescreen(std::string last_status)
{

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::endl;
	std::cout << "[[ AWESOME PHONEBOOK 1.0 ]]" << std::endl;
	std::cout << std::endl;
	if (last_status != " ")
	{
		std::cout << last_status << std::endl;
		std::cout << std::endl;
	}
	return ;
}

int main(void)
{
	std::string command;
	std::string last_status = " ";
	int			contacts = 8;
	PhoneBook 	Pbook;

	Pbook.contact_count = 0;
	ft_homescreen("Welcome!");
	while (1)
	{
		ft_homescreen(last_status);
		std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
		std::cin >> command;
		command = sb_tolower_str(command);
		
		if (command == "add")
		{
			ft_homescreen("ADD new contact:");
			if (contacts == 0)
				std::cout << "No more space. New contact will overwrite oldest one." << std::cout;
			std::cout << "Contacts remaining: " << contacts << std::endl;
			//std::cout << "ADD new contact: " << std::endl;
			if (Pbook.contact_count > 7)
				Pbook.contact_count = 0; // dodelat loop, kontakty se musi posouvat?

			std::cout << "First name: ";
			std::cin >> Pbook.ContactMem[Pbook.contact_count].first_name;

			std::cout << "Last name: ";
			std::cin >> Pbook.ContactMem[Pbook.contact_count].last_name;

			std::cout << "Nickname: ";
			std::cin >> Pbook.ContactMem[Pbook.contact_count].nickname;

			std::cout << "Phone: ";
			std::cin >> Pbook.ContactMem[Pbook.contact_count].phone_number;

			std::cout << "Darkest secret: ";
			std::cin >> Pbook.ContactMem[Pbook.contact_count].secret;
			
			Pbook.contact_count++;
			contacts--;
			last_status = "Contact saved!";
		}
		else if (command == "search")
		{
			
		}
		else if (command == "exit")
		{
			std::cout << "\033[2J\033[1;1H";
			break ;
		}
	}
	return 0;
}
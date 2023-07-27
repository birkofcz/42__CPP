/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/27 12:17:47 by sbenes           ###   ########.fr       */
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
	}
	return ;
}

void	ft_putcontact(std::string data)
{
	std::string temp = data;
	if (temp.length() < 10)
	{
		while (temp.length() < 10)
			temp.insert(0, " ");
	}
	else if (temp.length() >= 10)
		temp = temp.substr(0, 9) + ".";
	std::cout << temp << "|";
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
		//ft_homescreen(last_status);
		std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
		std::cin >> command;
		command = sb_tolower_str(command);
		
		if (command == "add")
		{
			ft_homescreen("ADD new contact:");
			if (contacts == 0)
				std::cout << "No more space. New contact will overwrite oldest one." << std::endl;
			std::cout << "Contacts remaining: " << contacts << std::endl;
			//std::cout << "ADD new contact: " << std::endl;
			if (Pbook.contact_count > 7)
				Pbook.contact_count = 0; // dodelat loop, kontakty se musi posouvat?
			std::cout << "test: " << Pbook.contact_count << std::endl;
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
			if (contacts != 0)
				contacts--;
			last_status = "Contact saved!";
		}
		else if (command == "search")
		{
			int i = 0;
			int j = 1;
			int index;

			while (j <= Pbook.contact_count)
			{
				std::cout << "  " << j << " "<< "|";
				ft_putcontact(Pbook.ContactMem[i].first_name);
				ft_putcontact(Pbook.ContactMem[i].last_name);
				ft_putcontact(Pbook.ContactMem[i].nickname);
				std::cout << std::endl;
				i++;
				j++;
			}
			std::cout << "Enter the index to show contact: ";
			std::cin >> index;
			while (1) {
				if (index > Pbook.contact_count || index < 1) 
				{
					std::cout << "Error: out of bounds. Enter again: ";
					std::cin >> index;
				}
				else if (index > 0 && index <= Pbook.contact_count)
				{
					std::cout << Pbook.ContactMem[index - 1].first_name << std::endl;
					std::cout << Pbook.ContactMem[index - 1].last_name << std::endl;
					std::cout << Pbook.ContactMem[index - 1].nickname << std::endl;
					std::cout << Pbook.ContactMem[index - 1].phone_number << std::endl;
					std::cout << Pbook.ContactMem[index - 1].secret << std::endl;
					std::cout << std::endl;
					break ;
				}
			}
		}
		else if (command == "exit")
		{
			std::cout << "\033[2J\033[1;1H";
			break ;
		}
	}
	return 0;
}
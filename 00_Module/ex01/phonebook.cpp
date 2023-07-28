/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:49 by sbenes            #+#    #+#             */
/*   Updated: 2023/07/27 14:32:50 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/* 
My function to return lowercase version of arg - for comparation purposes
 */
std::string sb_tolower_str(std::string src)
{
	std::string result;
	int i = -1;

	while (src[++i])
		result += tolower(src[i]);
	return result;
}

/* 
Clears the terminal screen
 */
void	ft_clear(void)
{
	std::cout << "\033[2J\033[1;1H";
}

/* 
Puts a contact to the screen, making it 10 chars long or trimming it as stated in subject
 */
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
	int			contacts = 8;
	int			index = 0;
	PhoneBook 	Pbook;

	Pbook.contact_count = 0;
	ft_clear();
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
		std::cin >> command;
		command = sb_tolower_str(command);
		
		if (command == "add")
		{
			ft_clear();
			if (contacts == 0)
				std::cout << "No more space. New contact will overwrite oldest one." << std::endl;
			std::cout << "Contacts remaining: " << contacts << std::endl;
			std::cout << "Writing on position: " << (index + 1) << std::endl;
			std::cout << "First name: ";
			std::cin >> Pbook.ContactMem[index].first_name;

			std::cout << "Last name: ";
			std::cin >> Pbook.ContactMem[index].last_name;

			std::cout << "Nickname: ";
			std::cin >> Pbook.ContactMem[index].nickname;

			std::cout << "Phone: ";
			std::cin >> Pbook.ContactMem[index].phone_number;

			std::cout << "Darkest secret: ";
			std::cin >> Pbook.ContactMem[index].secret;
			
			if (Pbook.contact_count != 8)
				Pbook.contact_count++;
			if (index != 7)
				index++;
			else if (index == 7)
				index = 0;
			if (contacts != 0)
				contacts--;
			ft_clear();
			std::cout << "Contact saved!" << std::endl;
		}
		else if (command == "search")
		{
			int i = 0;
			int j = 1;
			int ind;
			
			ft_clear();
			std::cout << std::endl;
			if (Pbook.contact_count == 0)
			{
				std::cout << "No contacts" << std::endl;
				continue;
			}
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
			std::cout << std::endl;
			std::cout << "Enter number to show contact: ";
			std::cin >> ind;
			while (1) {
				if (ind > Pbook.contact_count || ind < 1) 
				{
					std::cout << "Error: out of bounds. Enter again: ";
					std::cin >> ind;
				}
				else if (ind > 0 && ind <= Pbook.contact_count)
				{
					ft_clear();
					std::cout << Pbook.ContactMem[ind - 1].first_name << std::endl;
					std::cout << Pbook.ContactMem[ind - 1].last_name << std::endl;
					std::cout << Pbook.ContactMem[ind - 1].nickname << std::endl;
					std::cout << Pbook.ContactMem[ind - 1].phone_number << std::endl;
					std::cout << Pbook.ContactMem[ind - 1].secret << std::endl;
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
		else if (command != "add" && command != "search" && command != "exit")
		{
			ft_clear();
			continue ;
		}
	}
	return 0;
}
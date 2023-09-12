/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:24 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 15:37:52 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdlib>
#include <bitset>

void	printData(Data *data, std::string nameOfStructure)
{
	std::cout << "Data structure: " << nameOfStructure << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Number: " << data->number << std::endl;
	std::cout << "Pointer address: " << GRE << data << RES << std::endl;

}

int main(int ac, char** av)
{
	if (ac == 3)
	{
		Data data1;
		data1.name = av[1];
		data1.number = atoi(av[2]);
		
		std::cout << std::endl;
		printData(&data1, "data1");	
		
		std::cout << GRE <<  "\nSerializing...\n" << RES << std::endl;
		uintptr_t* raw = Serializer::serialize(&data1);

		std::cout << BLU << "Looking at the serialized pointer: " << RES << std::endl;
		std::cout << "Pointer address of raw: " << BLU << raw << RES << std::endl;
		std::cout << "Data binary representation of raw: " << BLU << std::bitset<64>(*raw) << RES << std::endl;

		std::cout << GRE << "\nDeserializing...\n" << RES << std::endl;
		Data* data2 = Serializer::deserialize(raw);
		printData(data2, "data2");
		std::cout << std::endl;
	}
	else
		return (std::cerr << "Wrong number of arguments" << std::endl, 1);
	return 0;

}

/* 
std::bitset<64> is a class template that represents an integer of 64 bits. 
 */
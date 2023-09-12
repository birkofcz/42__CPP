/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:11:51 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/12 15:44:16 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

# define RED "\033[31m"
# define GRE "\033[32m"   
# define YEL "\033[33m"
# define BLU "\033[34m"
# define RES "\033[0m"

struct Data
{
	std::string name;
	int number;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & src);
		~Serializer();

	public:
		static uintptr_t* serialize(Data* data);
		static Data* deserialize(uintptr_t* raw);
};

#endif

/* 
Serialization:
- It is the process of converting an object into a stream of bytes 
to store the object or transmit it to memory, a database, or a file.
- Its main purpose is to save the state of an object in order to be able 
to recreate it when needed. The reverse process is called deserialization.

tech behind: it is a process of converting an object into a stream of bytes. Usually, this is done to store the object in memory,
 a database, or a file, or to send it over the network. The reverse process is called deserialization.

In our excersice we will use reinterpret_cast to convert the pointer to the desired type - so this is not technically speaking serialization,
we only serialize the pointer, not the data it points to. But it is a good excersice to understand the concept of serialization.
 */

/* 
uintptr_t is an unsigned integer type that is capable of storing a data pointer.
 */
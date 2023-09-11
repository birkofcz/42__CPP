/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:22:39 by sbenes            #+#    #+#             */
/*   Updated: 2023/09/11 16:28:49 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//we will use reinterpret_cast to convert the pointer to the desired type

/* OCC */
Serializer::Serializer() {}

Serializer::Serializer(Serializer const & src)
{
    *this = src;
}

Serializer & Serializer::operator=(Serializer const & src)
{
    (void)src;
    return *this;
}

Serializer::~Serializer() {}

/* Methods */
 uintptr_t* Serializer::serialize(Data* data) {return (reinterpret_cast<uintptr_t*>(data));}
 
 Data* Serializer::deserialize(uintptr_t* raw) {return (reinterpret_cast<Data*>(raw));}

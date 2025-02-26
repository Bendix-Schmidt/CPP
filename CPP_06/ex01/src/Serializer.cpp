/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:47:58 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 13:26:05 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

//methods
uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

//constructors and destructor
Serializer::Serializer()
{}

//no definition of copy constructor or copy assignment operator as class is not instantiable

Serializer::~Serializer()
{}

//outstream operator, also kinda useless
std::ostream &operator<<(std::ostream &stream, Serializer const &serializer)
{
	(void)serializer;
	stream << "Serializer" << std::endl;
	return (stream);
}
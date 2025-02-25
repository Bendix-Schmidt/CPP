/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:03:40 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/25 16:13:12 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
	//methods
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
	
	private:
	//constructors
	Serializer();
	Serializer(const Serializer &original);
	Serializer &operator=(const Serializer &original);
	~Serializer();
};

std::ostream &operator<<(std::ostream &stream, Serializer const &serializer);

#endif // SERIALIZER_HPP
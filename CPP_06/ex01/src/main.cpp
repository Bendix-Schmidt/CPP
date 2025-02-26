/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:14:08 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 13:23:21 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data*	data = new Data;
	data->c 	= 'a';
	data->num	= 1;
	data->str	= "hello";
	
	std::cout <<
	"Oroginal char: " << data->c <<
	"\nOriginal num: " << data->num <<
	"\noriginal string: " << data->str <<
	std::endl; 

	//serializing
	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	//deserializing
	Data		*deserialized = Serializer::deserialize(serialized);
	std::cout <<
	"Deserialized char:" << deserialized->c <<
	"\nDeserialized num: " << deserialized->num <<
	"\nDeserialized string:" << deserialized->str <<
	std::endl; 

	if (deserialized == data) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

	delete(data);
}
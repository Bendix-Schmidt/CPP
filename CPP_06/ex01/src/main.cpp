/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:14:08 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:37 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data*	data = new Data;
	data->num = 1;
	data->str = "hello";
	
	std::cout << "original: " << data->num << " and " << data->str << std::endl; 

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;
}
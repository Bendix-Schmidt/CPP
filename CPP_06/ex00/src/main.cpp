/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:34 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/25 16:00:41 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Please use like this: ./convert [string-literal]" << std::endl;
	else
		ScalarConverter::convert(argv[1]);

	//ScalarConverter test; --> cant be instantiated
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:24:56 by bschmidt          #+#    #+#             */
/*   Updated: 2025/04/08 19:20:48 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong Input. Use like this: ./RPN 'Inverted polish mathematical expression.'" << std::endl;
		return 1;
	}

	std::string expression = argv[1];
	RPN rpn;
	try
	{
		int result = rpn.evaluate(expression);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
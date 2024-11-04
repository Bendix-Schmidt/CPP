/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/04 19:13:56 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{	
	//check nb Parameters
	if (argc != 2)
	{
		std::cerr << "Wrong amount of Arguments for this Program." << std::endl;
		return (1);
	}
	
	//check keywords
	std::string str;
	str = argv[1];
	if (str != "DEBUG" && str != "INFO" && str != "WARNING" && str != "ERROR")
	{
		std::cerr 	<< "Wrong Usage. Please use 'DEBUG', 'Info'," 
					<< " 'Warning' or 'Error' as Argument" << std::endl;
		return (2);
	}
	 //create Harl and Char c
	Harl	harl;
	char	c;
	
	//make char first letter of Argument to be able to use switch
	if (argv[1][0])
		c = argv[1][0];
	else
	{
		std::cout << "should never be printed!" << std::endl;
		return (3);
	}

	switch (c)
	{
		case 'D':
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 'I':
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 'W':
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 'E':
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			//break here to prevent default getting printed
			break ;
		default:
			std::cerr << "This should never be printed!!!" << std::endl;
			return (3);
	}
	return (0);
}
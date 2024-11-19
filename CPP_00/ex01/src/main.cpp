/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:05:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/09/26 14:25:04 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

void			prep_string(std::string& string)
{
	for (size_t i = 0; i < string.size(); i++)
	{
		if (string[i] > 8 && string[i] < 14)
			string[i] = 32;
	}
}

std::string		get_input(const std::string& prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		prep_string(input);
		if ((input.find_first_not_of(' ') != std::string::npos))
   			break;
	}
	return (input);
}

std::string		get_command(void)
{
	std::string	input;

	while (true)
	{
		if (std::cin.eof())
            break ;
		std::cout << "Please type 'ADD', 'SEARCH' or 'EXIT': ";
		std::getline(std::cin, input);
		if (input == "ADD" || input == "SEARCH" || input == "EXIT")
			break ;
		else
			std::cout << "invalid Input. Please try again." << std::endl;
	}
	return (input);
}

int	main(void)
{
	Phonebook 	phonebook;
	std::string input;

	while (1)
	{
		if (std::cin.eof())
            break;
		input = get_command();
		if (input == "EXIT")
			break ;
		if (input == "ADD")
			phonebook.create_contact();
		if (input == "SEARCH")
			phonebook.display_phonebook();
	}
	return (0);
}

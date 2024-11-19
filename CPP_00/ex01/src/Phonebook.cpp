/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:01:17 by bschmidt          #+#    #+#             */
/*   Updated: 2024/08/21 18:35:54 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

Phonebook::Phonebook()
{
	// Construct Phonebook Class
	this->contacts_count = 0;
}

Phonebook::~Phonebook()
{
	// Deconstruct Phonebook Class
}

void	Phonebook::create_contact(void)
{
	Contact			new_contact;
	std::string		input;
	
	new_contact.set_first_name(get_input("First Name"));
	new_contact.set_last_name(get_input("Last Name"));
	new_contact.set_nick_name(get_input("Nickname"));
	new_contact.set_phone_number(get_input("Phone Number"));
	new_contact.set_darkest_secret(get_input("Darkest Secret"));

	add_contact(new_contact);
}

void	Phonebook::add_contact(Contact contact)
{
	if (this->contacts_count < 8)
	{
		this->contacts[contacts_count] = contact;
		contacts_count++;
	}
	else
	{
		for (size_t i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		this->contacts[7] = contact;
	}
}

void	Phonebook::display_phonebook(void)
{
	if (this->contacts_count == 0)
	{
		std::cout << "You dont have any contacts yet" << std::endl;
		return ;
	}
	int	i = 0;
	while (i < this->contacts_count)
	{
		this->contacts[i].display_preview(i + 1);
		i++;
	}
	int index;
	while (true)
	{
		if (std::cin.eof())
            return ;
		std::cout << "Please give the index of the entry to display in full: ";
		std::string input;
		getline(std::cin, input);
		std::stringstream ss(input);
		if (!(ss >> index) || index < 1 || index > this->contacts_count)
			std::cout << "Invalid input. Please enter a number between 1 and " << this->contacts_count << "." << std::endl;
		else
			break ;
	}
	this->contacts[index - 1].display_full(index);
}
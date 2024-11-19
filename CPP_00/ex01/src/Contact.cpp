/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:00:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/08/21 19:46:49 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

Contact::Contact()
{
	// construct Contact Class	
}

Contact::~Contact()
{
	//deconstruct Contact Class
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nick_name(std::string nick_name)
{
	this->_nick_name = nick_name;
}			
			
void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void	Contact::display_preview(int index)
{
	std::string		first_name = this->_first_name.length() > 10 ? this->_first_name.substr(0,9) + "." : this->_first_name;
	std::string		last_name = this->_last_name.length() > 10 ? this->_last_name.substr(0,9) + "." : this->_last_name;
	std::string		nick_name = this->_nick_name.length() > 10 ? this->_nick_name.substr(0,9) + "." : this->_nick_name;
	
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << first_name << "|";
	std::cout << std::setw(10) << std::right << last_name << "|";
	std::cout << std::setw(10) << std::right << nick_name << "|";
	std::cout << std::endl;
}

void	Contact::display_full(int index)
{
	std::cout << "Index:\t" << index << std::endl;
	std::cout << "First Name:\t" << _first_name << std::endl;
	std::cout << "Last Name:\t" << _last_name << std::endl;
	std::cout << "Nickname:\t" << _nick_name << std::endl;
	std::cout << "Phone Number:\t" << _phone_number << std::endl;
	std::cout << "Darkest Secret:\t" << _darkest_secret << std::endl;
}
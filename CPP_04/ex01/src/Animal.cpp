/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:04:18 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 15:12:03 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

//member function
void	Animal::makeSound() const
{
	std::cout << "some animal sound" << std::endl;
}

//getter
std::string	Animal::get_type(void) const
{
	return (this->type);
}

//setter
void	Animal::set_type(std::string type)
{
	this->type = type;
}

/*---------------------------------------------------------*/
//constructor
Animal::Animal()
{
	this->type = "unassigned animal";
	std::cout << "An Animal was created." << std::endl;
}

//copy constructor
Animal::Animal(const Animal& other)
{
	*this = other;
}

//copy assignment operator
Animal	&Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//destructor
Animal::~Animal()
{
	std::cout << "An Animal died." << std::endl;
}

//overload
std::ostream	&operator<<(std::ostream &stream, Animal const &animal)
{
	stream << animal.get_type() << std::endl;
	return (stream);
}
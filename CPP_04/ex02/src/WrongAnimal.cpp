/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:04:18 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 15:30:41 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

//member function
void	WrongAnimal::makeSound() const
{
	std::cout << "some wrong animal sound" << std::endl;
}

//getter
std::string	WrongAnimal::get_type(void) const
{
	return (this->type);
}

//setter
void	WrongAnimal::set_type(std::string type)
{
	this->type = type;
}

/*---------------------------------------------------------*/
//constructor
WrongAnimal::WrongAnimal()
{
	this->type = "unassigned wrong animal";
	std::cout << "A wrong Animal was created." << std::endl;
}

//copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
}

//copy assignment operator
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "A wrong Animal died." << std::endl;
}

//overload
std::ostream	&operator<<(std::ostream &stream, WrongAnimal const &WrongAnimal)
{
	stream << WrongAnimal.get_type() << std::endl;
	return (stream);
}
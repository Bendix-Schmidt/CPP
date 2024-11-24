/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:59:10 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/22 16:58:56 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//member function
void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

/*----------------------------------------------------------*/
//constructor
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "A Dog was born." << std::endl;
}

//copy constructor
Dog::Dog(const Dog &original) : Animal(original)
{
	*this = original;
}

//copy assignment operator
Dog&	Dog::operator=(const Dog &original)
{
	if (this != &original)
	{
		this->type = original.type;
	}
	return (*this);
}

//destructor
Dog::~Dog()
{
	std::cout << "A Dog died." << std::endl;
}

//<< operator
std::ostream	&operator<<(std::ostream &stream, Dog const &Dog)
{
	stream << Dog.get_type() << std::endl;
	return (stream);
}

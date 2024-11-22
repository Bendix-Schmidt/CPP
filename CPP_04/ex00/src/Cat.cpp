/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:58:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/22 15:32:07 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//member function
void	Cat::makeSound() const
{
	std::cout << "Meoooww" << std::endl;
}

/*----------------------------------------------------------*/
//constructor
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "A Cat was born." << std::endl;
}

//copy constructor
Cat::Cat(const Cat &original) : Animal(original)
{
	*this = original;
}

//copy assignment operator
Cat&	Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
		this->type = original.type;
	}
	return (*this);
}

//destructor
Cat::~Cat()
{
	std::cout << "A Cat died." << std::endl;
}

//<< operator
std::ostream	&operator<<(std::ostream &stream, Cat const &cat)
{
	stream << cat.get_type() << std::endl;
	return (stream);
}

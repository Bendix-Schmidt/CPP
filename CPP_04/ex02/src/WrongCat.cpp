/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:58:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 15:30:43 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

//member function
void	WrongCat::makeSound() const
{
	std::cout << "kikeriki" << std::endl;
}

/*----------------------------------------------------------*/
//constructor
WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "A WrongCat was born." << std::endl;
}

//copy constructor
WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
	*this = original;
}

//copy assignment operator
WrongCat&	WrongCat::operator=(const WrongCat &original)
{
	if (this != &original)
	{
		this->type = original.type;
	}
	return (*this);
}

//destructor
WrongCat::~WrongCat()
{
	std::cout << "A WrongCat died." << std::endl;
}

//<< operator
std::ostream	&operator<<(std::ostream &stream, WrongCat const &wrongcat)
{
	stream << wrongcat.get_type() << std::endl;
	return (stream);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:14:43 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 18:55:48 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

//member functions
AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.get_name() << std::endl;
}

//constructor
Ice::Ice() : AMateria("ice"){}

Ice::~Ice(){}
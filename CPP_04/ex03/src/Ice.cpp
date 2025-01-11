/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:14:43 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/11 18:28:33 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

//member functions
Ice*	Ice::clone() const
{
	return (Ice*)this;
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.get_name() << std::endl;
}

//constructor
Ice::Ice() : AMateria("ice")
{
}

//copy constructor
Ice::Ice(const Ice& other) : AMateria(other)
{
}

//copy assigment operator
Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
	{
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice()
{
}
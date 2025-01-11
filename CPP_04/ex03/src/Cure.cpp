/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:22 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/11 18:28:14 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//member functions
Cure*	Cure::clone() const
{
	return (Cure*)this;
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.get_name() << "'s wounds.*" << std::endl;
}

//constructor
Cure::Cure() : AMateria("cure")
{
}

//copy constructor
Cure::Cure(const Cure& other) : AMateria(other)
{
}

//copy assigment operator
Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
	{
        AMateria::operator=(other);
    }
    return *this;
}

//destructor
Cure::~Cure()
{
}
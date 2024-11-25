/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:22 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 18:55:30 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//member functions
AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.get_name() << "'s wounds.*" << std::endl;
}

//constructor
Cure::Cure() : AMateria("cure"){}

Cure::~Cure(){}
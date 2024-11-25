/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:41:19 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 19:37:32 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//getter
std::string const &AMateria::get_type() const
{
	return (this->type);
}

//default implementation of use cause needed by compiler
void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses materia on " << target.get_name() << " *" << std::endl;
}

//constructor
AMateria::AMateria(std::string const &type) : type(type)
{
	//this->type = type;
}

//destructor
AMateria::~AMateria(){}
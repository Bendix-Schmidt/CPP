/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:41:19 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 16:54:46 by bschmidt         ###   ########.fr       */
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
}

//copy constructor
AMateria::AMateria(const AMateria &other)
{
	type = other.type;
}

//copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
	{
        type = other.type;
    }
    return *this;
}

//default constructor
AMateria::AMateria() : type("empty slot")
{
}

//destructor
AMateria::~AMateria(){}
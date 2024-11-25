/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:03:54 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 19:20:30 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//constructor
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		templates[i] = NULL;
	}
}
//copy constructor
MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}
//copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i) {
			delete templates[i];
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = NULL;
		}
	}
	return *this;
}
//destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
	{
        delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (templates[i] == NULL)
		{
            templates[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
	{
        if (templates[i] != NULL && templates[i]->get_type() == type)
		{
            return templates[i]->clone();
        }
    }
    return NULL;
}
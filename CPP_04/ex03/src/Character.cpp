/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:25:17 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 19:30:51 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//member functions
std::string const & Character::get_name() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (inv[i] == NULL)
		{
            inv[i] = m;
            break ;
        }
    }
}
	
void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
	{
		std::cout << "Index is out of inventory range. Unequipping unsuccesfull." << std::endl;
    }
	else
		inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "inventory index out of range." << std::endl;
		return ;
	}
	if (this->inv[idx] == NULL)
	{
		std::cout << "No Materia at this inventory index." << std::endl;
	}
	else
		this->inv[idx]->use(target);
}

/*---------------------------------------------------------------------------------------*/

//constructor:
Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; ++i)
	{
        inv[i] = NULL;
    }
}

//copy constrcutor:
Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; ++i)
	{
        inv[i] = (other.inv[i]) ? other.inv[i]->clone() : NULL;
    }
}

//copy assignment operator:
Character& Character::operator=(const Character& other)
{
    if (this != &other)
	{
        name = other.name;
        for (int i = 0; i < 4; ++i)
		{
            delete inv[i];
            inv[i] = (other.inv[i]) ? other.inv[i]->clone() : NULL;
        }
    }
    return *this;
}

//destructor:
Character::~Character()
{
    for (int i = 0; i < 4; ++i)
	{
        delete inv[i];
    }
}
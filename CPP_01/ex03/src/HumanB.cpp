/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:54:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/04 17:51:31 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " had no weapon to attack" << std::endl;
	else
	{
		std::string type = this->_weapon->getType();
		std::cout << _name << " attacks with their " << type << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
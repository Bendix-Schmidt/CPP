/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:54:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/31 18:47:24 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() const
{
	std::string	type;

	type = weapon.getType();
	std::cout << _name << " attacks with their " << type << std::endl;
}
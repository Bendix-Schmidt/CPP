/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:54:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/04 17:36:54 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& _weapon) : _name(name), _weapon(_weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() const
{
	std::string	type;

	type = _weapon.getType();
	std::cout << _name << " attacks with their " << type << std::endl;
}
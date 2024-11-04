/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:25 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/30 18:33:36 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	_type = type;
}

Weapon::~Weapon() {}

const	std::string& Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
}
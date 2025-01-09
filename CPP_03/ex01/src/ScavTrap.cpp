/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:44:58 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 12:31:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//member functions
void	ScavTrap::attack(const std::string& target)
{
	if (get_EP() > 0 && get_HP() > 0)
	{
		std::cout << get_name() << " the Scavtrap attacks " << target << " and does " << get_AD() << " damage!" << std::endl;
		int x = get_EP() - 1;
		set_EP(x);
	}
	else if (get_HP() > 0 && get_EP() == 0)
		std::cout << get_name() << " the Scavtrap tries to attack, but does not have enough EP left!" << std::endl;
	else if (get_EP() > 0 && get_HP() == 0)
		std::cout << get_name() << " the Scavtrap tries to attack, but does not have any HP left!" << std::endl;
	else
		std::cout << get_name() << " the Scavtrap tries to attack, but neither has EP nor HP left!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->get_name() << " is now in Gate Keeper mode" << std::endl;
}

//standard constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << name << " was born as a ScavTrap" << std::endl;
	set_HP(100);
	set_EP(50);
	set_AD(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " was born as a ScavTrap" << std::endl;
	set_name(name);
	set_HP(100);
	set_EP(50);
	set_AD(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for " << other.get_name() << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap copy assignment operator called for " << other.get_name() << std::endl;
    }
    return *this;
}

//standard destructor
ScavTrap::~ScavTrap()
{
       std::cout << this->get_name() << " the ScavTrap died" << std::endl;
}


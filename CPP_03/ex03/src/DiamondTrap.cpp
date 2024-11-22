/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 19:40:45 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//member function
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::get_name() << std::endl;
}

//standard constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	set_HP(100); // From FragTrap
	set_EP(50);  // From ScavTrap
	set_AD(30);  // From FragTrap
	std::cout << "DiamondTrap " << name << " created." << std::endl;
}

//copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << name << " copied." << std::endl;
}

//copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
        std::cout << "DiamondTrap " << name << " assigned." << std::endl;
    }
    return *this;
}

//standard destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destroyed." << std::endl;
}
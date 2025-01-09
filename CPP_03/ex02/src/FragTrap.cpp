/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:17 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 12:35:00 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//member function
void	FragTrap::highFivesGuys(void)
{
	std::cout << this->get_name() << " would really like a highfive from you :)" << std::endl;
}

//standard constrcutor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << name << " was born as a FragTrap!" << std::endl;
	set_HP(100);
	set_EP(100);
	set_AD(30);
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " was born as a FragTrap!" << std::endl;
	set_HP(100);
	set_EP(100);
	set_AD(30);
}

//copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << other.get_name() << std::endl;
}

//copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap copy assignment operator called for " << other.get_name() << std::endl;
    }
    return *this;
}

//standard destrcutor
FragTrap::~FragTrap()
{
	std::cout << this->get_name() << " the Fragtrap died" << std::endl;
}
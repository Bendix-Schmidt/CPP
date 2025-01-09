/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:17 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/17 17:37:22 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ClapTrap.hpp"

//MEMBER FUNCTIONS
void	ClapTrap::attack(const std::string& target)
{
	if (EP > 0 && HP > 0)
	{
		std::cout << name << " attacks " << target << " and does " << AD << " damage!" << std::endl;
		EP -= 1;
	}
	else if (HP > 0 && EP == 0)
		std::cout << name << " tries to attack, but does not have enough EP left!" << std::endl;
	else if (EP > 0 && HP == 0)
		std::cout << name << " tries to attack, but does not have any HP left!" << std::endl;
	else
		std::cout << name << " tries to attack, but neither has EP nor HP left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (HP <= 0)
	{
		std::cout << name << " is already out of HP, stop hitting please!" << std::endl;
		return ;
	}
	HP -= amount;
	std::cout << name << " took " << amount << " damage" << std::endl;
	if (HP <= 0)
	{
		std::cout << name << " lost its remaining HP from this attack" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (HP <= 0 && EP <= 0)
	{
		std::cout << name << " would like to repair itself, but neither has HP or EP left" << std::endl;
		return ;
	}
	if (HP <= 0)
	{
		std::cout << name << " would like to repair itself, but has no HP left" << std::endl;
		return ;
	}
	if (EP <= 0)
	{
		std::cout << name << " would like to repair itself, but does not have any EP left" << std::endl;
		return ;
	}
	HP += amount;
	EP -= 1;
	std::cout << name << " got " << amount << " HP back" << std::endl;
	if (EP == 0)
		std::cout << name << " does not have any EP left after repairing" << std::endl;
}

//getters
std::string ClapTrap::get_name() const
{
	return (name);
}
int	ClapTrap::get_HP() const
{
	return (HP);
}
int	ClapTrap::get_EP() const
{
	return (EP);
}
int	ClapTrap::get_AD() const
{
	return (AD);
}
//setters
void	ClapTrap::set_name(std::string name)
{
	this->name = name;	
}
void	ClapTrap::set_HP(int amount)
{
	HP = amount;
}
void	ClapTrap::set_EP(int amount)
{
	EP = amount;
}
void	ClapTrap::set_AD(int amount)
{
	AD = amount;
}

//Constructors & Deconstructors
//standard constructor
ClapTrap::ClapTrap() : name("anonymous")
{
	std::cout << "anonymous claptrap born" << std::endl;
	HP = 10;
	EP = 10;
	AD = 0;
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout << name << " was born" << std::endl;
	this->name = name;
	HP = 10;
	EP = 10;
	AD = 0;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other; 
}

//copy assignment Operator
ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.get_name();
		this->HP = other.get_HP();
		this->EP = other.get_EP();
		this->AD = other.get_AD();
		return (*this);
		//alternative logic that would also work, 
		//because member functions have access to private members:
	 	/* this->name = other.name;
            this->HP = other.HP;
            this->EP = other.EP;
            this->AD = other.AD; */
	}
	return (*this);
}



std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap)
{
	stream << "HP: " << clapTrap.get_HP() << "\n"
			  << "EP: " << clapTrap.get_EP() << "\n"
			  << "AD: " << clapTrap.get_AD() << std::endl;
	return (stream);
}

//standard deconstructor
ClapTrap::~ClapTrap()
{
	std::cout << name << " died" << std::endl;
}
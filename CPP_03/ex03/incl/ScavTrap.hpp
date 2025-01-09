/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:32 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/17 17:28:57 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
	
	public:
		//individual member functions (exceeding or overriding ClapTrap class):
		void guardGate();
		void attack(const std::string& target);
		
		//standard constructor
		ScavTrap();
		ScavTrap(std::string name);

		// Copy constructor
		ScavTrap(const ScavTrap& other);

		// Copy assignment operator
   		ScavTrap& operator=(const ScavTrap& other);
		
		//individual overriding destructor
		~ScavTrap();
		
};

#endif // SCAVTRAP_HPP
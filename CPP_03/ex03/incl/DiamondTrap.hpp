/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:13 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 12:47:49 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;

	public:
		//individual member function:
		void whoAmI();
	
		//constructor
		DiamondTrap();
		DiamondTrap(std::string name);
		
		//copy constructor
		DiamondTrap(const DiamondTrap& other);

		//copy assignment constructor
    	DiamondTrap& operator=(const DiamondTrap& other);
		//destructor
		~DiamondTrap();

};

#endif // DIAMONDTRAP_HPP
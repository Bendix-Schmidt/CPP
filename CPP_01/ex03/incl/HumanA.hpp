/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:21:18 by bschmidt          #+#    #+#             */
/*   Updated: 2024/10/31 18:47:27 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string _name;
		Weapon&		weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
		void	attack() const;
};

#endif // HUMANA_HPP
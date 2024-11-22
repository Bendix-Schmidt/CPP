/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 19:26:26 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
	private:

	public:
	//individual member function 
	void highFivesGuys(void);

	//standard constructor
	FragTrap(std::string name);
	// Copy constructor
	FragTrap(const FragTrap& other);
	// Copy assignment operator
   	FragTrap& operator=(const FragTrap& other);
	//destructor
	~FragTrap();
};

#endif //FRAGTRAP_HPP
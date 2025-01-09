/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:33:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/17 17:05:16 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdio>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int			HP;
		int			EP;
		int			AD;
	
	public:
		//member functions
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//getter functions (not really necessary here)
		std::string get_name() const;
		int			get_HP() const;
		int			get_EP() const;
		int			get_AD() const;

		//setter functions (not really necessary here as well)
		void		set_name(std::string name);
		void		set_HP(int amount);
		void		set_EP(int amount);
		void		set_AD(int amount);

		//Constructor and Deconstructor
		//standard constructor
		ClapTrap();
		ClapTrap(const std::string name);
		
		//copy constructor
		ClapTrap(const ClapTrap& other);

		//copy assignment Operator
		ClapTrap& operator=(const ClapTrap& other);	
			
		//standard deconstrucor
		virtual ~ClapTrap();
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap);

#endif // CLAPPTRAPP_HPP

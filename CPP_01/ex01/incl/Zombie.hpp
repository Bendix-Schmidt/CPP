/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:21:18 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/26 10:48:19 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
    	std::string _name;
		int			_index;

	public:
    	Zombie();
    	~Zombie();
		
    	void announce();
		void set_name(std::string name);
		void set_index(int index);
};

Zombie	*zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:16 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 18:52:14 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
   		std::string name;
		AMateria* 	inv[4];

	public:
		//getter
		std::string const & get_name() const;
		
		//member function
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printInventory() const;
		
		//standard constructor
		Character();
		Character(std::string const & name);
		//copy constructor
		Character(const Character& other);
		//copy assignment operator
		Character& operator=(const Character& other);
		//destructor
		virtual ~Character();
};

#endif // CHARACTER_HPP
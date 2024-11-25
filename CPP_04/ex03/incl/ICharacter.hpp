/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:30:14 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 19:03:15 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <string>
class AMateria;

class ICharacter
{
	public:
		//destructor
		virtual ~ICharacter() {}

		//getter
		virtual std::string const & get_name() const = 0;
		
		//member functions
		virtual void	equip(AMateria* m) = 0;
		virtual	void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

#endif // ICHARACTER_HPP
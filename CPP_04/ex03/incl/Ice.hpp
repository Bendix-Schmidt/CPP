/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:20:41 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 18:55:56 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
	public:
		//member functions
		AMateria	*clone() const;
		void		use(ICharacter &target);

		//constructor
		Ice();
		~Ice();
};

#endif // ICE_HPP
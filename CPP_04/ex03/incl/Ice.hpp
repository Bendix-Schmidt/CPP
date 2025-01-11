/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:20:41 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/11 18:27:34 by bschmidt         ###   ########.fr       */
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
		Ice		*clone() const;
		void	use(ICharacter &target);

		//constructor
		Ice();
		//copy constructor
		Ice(const Ice& other);
		//copy assignment operator
		Ice& operator=(const Ice& other);
		//destructor
		~Ice();
};

#endif // ICE_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:28:37 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 18:55:19 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
	public:
		//member functions
		AMateria	*clone() const;
		void		use(ICharacter &target);

		//constructor
		Cure();
		//destructor
		~Cure();
};

#endif // CURE_HPP
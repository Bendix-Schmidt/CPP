/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:28:37 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/11 18:27:58 by bschmidt         ###   ########.fr       */
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
		Cure	*clone(void) const;
		void	use(ICharacter &target);

		//standard constructor
		Cure();
		//copy constructor
		Cure(const Cure& other);
		//copy assignment operator
		Cure& operator=(const Cure& other);
		//destructor
		~Cure();
};

#endif // CURE_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:16:09 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 17:06:42 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	
	public:
		//constructor:
		AMateria(std::string const &type);

		//destructor
		virtual ~AMateria();
		
		//getter
		std::string const &get_type() const;

		//member functions:
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP
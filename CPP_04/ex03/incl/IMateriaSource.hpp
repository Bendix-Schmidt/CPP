/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:40:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 18:43:59 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP
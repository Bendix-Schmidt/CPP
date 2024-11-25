/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterSource.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:35:19 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/25 17:53:58 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* templates[4];
		
	public:
		//member functions
		void	learnMateria(AMateria* m);
		AMateria* createMateria(std::string const &type);

		//constructor
		MateriaSource();
		//copy constructor
		MateriaSource(const MateriaSource& other);
		//copy assignment operator
    	MateriaSource& operator=(const MateriaSource& other);
		//destructor
		virtual ~MateriaSource();
};

#endif // IMATERIASOURCE_HPP
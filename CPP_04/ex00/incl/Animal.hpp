/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 20:15:39 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	
	public:
		//member functions
		virtual void	makeSound();
	
		//getter
		std::string	get_type();

		//setter
		void	set_type();

		//standard constructor
		Animal();
		//copy constructor
		Animal(const Animal &other);
		//copy assignemnt operator
		Animal& operator=(const Animal &other);
		//standard destructor
		virtual ~Animal();
};


#endif // ANIMAL_HPP

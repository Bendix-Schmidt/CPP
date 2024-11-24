/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 20:57:18 by bschmidt         ###   ########.fr       */
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
		virtual void	makeSound() const = 0;

		//getter
		std::string	get_type() const;

		//setter
		void	set_type(std::string type);

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

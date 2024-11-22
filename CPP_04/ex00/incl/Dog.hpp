/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:18:24 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 20:19:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		//individual member function
		void makeSound();

		//standard constructor
		Dog();
		//copy constructor
		Dog(const Dog &other);
		//copy assignment operator
		Dog& operator=(const Dog &other);
		//standard destructor
		~Dog();
};

#endif // DOG_HPP
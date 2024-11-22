/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:13:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/20 20:17:56 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		//individual member function
		void makeSound();

		//standard constructor
		Cat();
		//copy constructor
		Cat(const Cat &other);
		//copy assignment operator
		Cat& operator=(const Cat &other);
		//standard destructor
		~Cat();
};

#endif // CAT_HPP
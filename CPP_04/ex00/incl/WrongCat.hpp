/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:13:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/22 15:03:33 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		//individual member function
		void makeSound() const;

		//standard constructor
		WrongCat();
		//copy constructor
		WrongCat(const WrongCat &other);
		//copy assignment operator
		WrongCat& operator=(const WrongCat &other);
		//standard destructor
		~WrongCat();
};

#endif // WRONGCAT_HPP
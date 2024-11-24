/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:03:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/22 15:00:27 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		//member functions
		void	makeSound() const;
	
		//getter
		std::string	get_type() const;

		//setter
		void	set_type(std::string type);

		//standard constructor
		WrongAnimal();
		//copy constructor
		WrongAnimal(const WrongAnimal &other);
		//copy assignemnt operator
		WrongAnimal& operator=(const WrongAnimal &other);
		//standard destructor
		~WrongAnimal();
};


#endif // WRONGANIMAL_HPP

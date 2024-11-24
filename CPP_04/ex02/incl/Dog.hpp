/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:18:24 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 19:58:05 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *brain;
		
	public:
		//individual member function
		void makeSound() const;

		//getter
		std::string get_idea(int index) const;

		//setter
		void	set_idea(int index, std::string idea);
		void	set_ideas(std::string ideas);

		//printer
		void 	print_first_idea(std::ostream &stream) const;
   		void 	print_all_ideas(std::ostream &stream) const;
		void 	print_specific_idea(std::ostream &stream, int index) const;
		
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
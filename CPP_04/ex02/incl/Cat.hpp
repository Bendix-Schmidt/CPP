/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:13:05 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 19:57:40 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		//individual member function
		void	makeSound() const;

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
		Cat();
		//copy constructor
		Cat(const Cat &other);
		//copy assignment operator
		Cat& operator=(const Cat &other);
		//standard destructor
		~Cat();
};

#endif // CAT_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:52:45 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/24 20:28:10 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];			

	public:
		//getter
		std::string	get_idea(int i) const;
		
		//setter
		void		set_idea(int i, std::string idea);
		void		set_ideas(std::string idea);

		//printers
		void 		print_first_idea(std::ostream &stream) const;
		void		print_specific_idea(std::ostream &stream, int index) const;
		void		print_all_ideas(std::ostream &stream) const;

		//constructors and deconstructor
		Brain();
		~Brain();
		Brain(const Brain &original);
		Brain& operator=(const Brain &original);
};

#endif // BRAIN_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:47:53 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 14:34:46 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		//member function
		AForm	*makeForm(std::string formname, std::string target);

		//standard & default constrcutor
		Intern();
		//copy constuctor
		Intern(const Intern &original);
		//copy assignment operator
		Intern &operator=(const Intern &original);
		//destructor
		~Intern();
	
		class FormCreationError: public std::exception
		{
			virtual const char *what() const throw();	
		};
};

std::ostream	&operator<<(std::ostream &os, Intern const &intern);

#endif // INTERN_HPP
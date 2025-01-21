/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:27:08 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:35:32 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	//inherits all the attributes from AForm plus target-string which will be the name of the file to bet created
	private:
		std::string target;

	public:
		//member functions
		void	getExecuted() const;

		//getter
		std::string	getTarget() const;

		//default constructor
		ShrubberyCreationForm();
		//standard constructor
		ShrubberyCreationForm(std::string target);
		//copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		//copy assignment operator
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		//destructor
		~ShrubberyCreationForm();
};


#endif // SHRUBBERYCREATIONFORM_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:36:48 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 13:37:51 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	
	public:
		//member function
		void	getExecuted() const;


		//default constructor
		PresidentialPardonForm();
		//standard constructor
		PresidentialPardonForm(std::string target);
		//copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &original);
		//copy assignment operator
		PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
		//destructor
		~PresidentialPardonForm();
};

#endif // PRESIDENTIALPARDONFORM_HPP
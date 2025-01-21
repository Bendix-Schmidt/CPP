/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:26:41 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:41:06 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTCLASS_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"



class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	
	public:
		//default constructor
		RobotomyRequestForm();
		//standard constructor
		RobotomyRequestForm(std::string target);
		//copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &original);
		//copy assignment operator
		RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		//destructor
		~RobotomyRequestForm();
};

#endif // ROBOTOMYREQUESTFORM_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:39 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:40:30 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"

//default constructor
RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", false, 145, 137)
{}

//standard constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", false, 145, 137), target(target)
{}

//copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) :
AForm(original)
{
	*this = original;
}
//copy assignment operator

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	if (this != &original)
		this->target = original.getTarget();
	return (*this);
}

//destructor
RobotomyRequestForm::~RobotomyRequestForm()
{}

//outsream operator
std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &form)
{
	os << form.getName() << std::endl;
	return (os);
}
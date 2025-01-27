/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:39 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/27 14:41:40 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"
#include "AForm.hpp"

//member function
void	RobotomyRequestForm::getExecuted() const
{
	std::srand(std::time(0)); //seeding random number generator with current time for different sequence
	std::cout << "*** DRILLING NOISE ***" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed :(" << std::endl;
}

//default constructor
RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", false, 72, 45, NULL)
{}

//standard constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", false, 72, 45, target)
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
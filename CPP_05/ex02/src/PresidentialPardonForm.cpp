/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:38:25 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 13:41:51 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"
#include "AForm.hpp"

//member function
void	PresidentialPardonForm::getExecuted() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	
}

//default constructor
PresidentialPardonForm::PresidentialPardonForm() : 
AForm("PresidentialPardonForm", false, 25, 5, NULL)
{}

//standard constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", false, 25, 5, target)
{}

//copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) :
AForm(original)
{
	*this = original;
}
//copy assignment operator

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	if (this != &original)
		this->target = original.getTarget();
	return (*this);
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{}

//outsream operator
std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &form)
{
	os << form.getName() << std::endl;
	return (os);
}
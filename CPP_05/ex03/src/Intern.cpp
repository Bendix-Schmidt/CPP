/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:04:58 by bschmidt          #+#    #+#             */
/*   Updated: 2025/03/04 17:59:38 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

AForm*	Intern::makeForm(std::string formname, std::string target)
{
	//creating array with all formnames to loop through
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	
	while (i < 3)
	{
		if (forms[i] == formname)
			break ;
		else
			i++;
	}
	if (i == 3)
	{
		throw Intern::FormCreationError();
		return NULL;
	}
	std::cout << forms[i] << " is about to be created!" << std::endl;
	switch(i)
	{
		//dont need breaks as return stops switch
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw  Intern::FormCreationError();
	}
	return NULL;
}




//Exception:
const char *Intern::FormCreationError::what() const throw()
{
	return "Could not create Form, useless intern";
}

//standard constructor
Intern::Intern()
{}
//copy constructor
Intern::Intern(const Intern &original)
{
	*this = original;
}
//copy assignment operator
Intern &Intern::operator=(const Intern &original)
{
	if (this != &original)
		return *this;
	return *this;
}
//destructor
Intern::~Intern()
{}

//outstream
std::ostream	&operator<<(std::ostream &os, Intern const &original)
{
	(void)original;

	os << "Some Intern" << std::endl;
	return (os);
}
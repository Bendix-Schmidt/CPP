/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:46:52 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:59:31 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"
#include "AForm.hpp"

//member functions:
void	ShrubberyCreationForm::getExecuted() const
{
	std::string		filename = "./" + this->getTarget() + "_scf";
	std::ofstream	os(filename.c_str());

	if (os.is_open()) //not really necessary, but good to know for future :)
	{
		os << "    ccee88oo          " << std::endl;
		os << "  C8O8O8Q8PoOb o8oo  " << std::endl;
		os << " dOB69QO8PdUOpugoO9bD" << std::endl;
		os << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
		os << "    6OuU  /p u gcoUodpP" << std::endl;
		os << "      \\\\//  /douUP" << std::endl;
		os << "        \\\\////" << std::endl;
		os << "         |||/\\  " << std::endl;
		os << "         |||\\/  " << std::endl;
		os << "         |||||   " << std::endl;
		os << "   .....//||||\\...." << std::endl;
	}
	else
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
	}
	//no need to write "os.close();" in the end, as the destructor
	//for the std::ofstream object gets called immediately after using it anyway
	//and file gets closed there 
	
}

//default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm", false, 145, 137, NULL)
{}

//standard constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", false, 145, 137, target)
{}

//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) :
AForm(original)
{
	*this = original;
}
//copy assignment operator

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	if (this != &original)
		this->target = original.getTarget();
	return (*this);
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

//outsream operator
std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &form)
{
	os << form.getName() << std::endl;
	return (os);
}
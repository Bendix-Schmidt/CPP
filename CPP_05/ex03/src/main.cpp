/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:21 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 14:42:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
Bureaucrat Bob("Bob", 1);
	
	{
		std::cout << std::endl << "--- Test Robotomy Form ---" << std::endl;
		Intern	someRandomIntern;
		AForm	*form = someRandomIntern.makeForm("Robotomy Request Form", "Target");
		std::cout << Bob << *form;
		Bob.signForm(*form);
		Bob.executeForm(*form);
		delete(form);
	}

	{
		std::cout << std::endl << "--- Test Shrubbery Form ---" << std::endl;
		Intern	someRandomIntern;
		AForm	*form = someRandomIntern.makeForm("Shrubbery Creation Form", "Target");
		std::cout << Bob << *form;
		Bob.signForm(*form);
		Bob.executeForm(*form);
		delete(form);
	}

	{
		std::cout << std::endl << "--- Test Presidential Form ---" << std::endl;
		Intern	someRandomIntern;
		AForm	*form = someRandomIntern.makeForm("Presidential Pardon Form", "Target");
		std::cout << Bob << *form;
		Bob.signForm(*form);
		Bob.executeForm(*form);
		delete(form);
	}

	{
		std::cout << std::endl << "--- Test Fail Form ---" << std::endl;
		Intern	someRandomIntern;
		AForm	*form = NULL;

		try
		{
			form = someRandomIntern.makeForm("Epic Fail Form", "Target");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
		if (form)
		{
			std::cout << Bob << *form;
			Bob.signForm(*form);
			Bob.executeForm(*form);
		}
		delete(form);
	}
	
}
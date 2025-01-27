/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:21 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/27 15:01:45 by bschmidt         ###   ########.fr       */
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
	std::cout << "--- Test Robotomy Form ---" << std::endl;
	Intern	someRandomIntern;
	AForm	*form = NULL;
	try
	{
		form = someRandomIntern.makeForm("RobotomyRequestForm", "Target");
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

	std::cout << std::endl;
	
	std::cout << std::endl << "--- Test Shrubbery Form ---" << std::endl;
	form = NULL;
	try
	{
		form = someRandomIntern.makeForm("ShrubberyCreationForm", "Target");
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

	std::cout << std::endl;
	
	std::cout << "--- Test Presidential Form ---" << std::endl;
	form = NULL;
	try
	{
		form = someRandomIntern.makeForm("PresidentialPardonForm", "Target");
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

	std::cout << std::endl;
	std::cout << std::endl << "--- Test Fail Form ---" << std::endl;
	form = NULL;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:42:21 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 16:14:31 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "--- Test Shrubbery Form ---" << std::endl;
		ShrubberyCreationForm shrubb("shrubb");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << shrubb << Harry << Ron;
		Harry.executeForm(shrubb);
		Ron.executeForm(shrubb);
		Harry.signForm(shrubb);
		Ron.signForm(shrubb);
		Harry.executeForm(shrubb);
		Ron.executeForm(shrubb);
	}
	std::cout << "\n\n\n" << std::endl;
	{
		std::cout << std::endl << "--- Test Robotomy Form ---" << std::endl;
		RobotomyRequestForm robo("robo");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << robo << Harry << Ron;
		Harry.executeForm(robo);
		Ron.executeForm(robo);
		Harry.signForm(robo);
		Ron.signForm(robo);
		Harry.executeForm(robo);
		Ron.executeForm(robo);
	} 

/* 	{
		std::cout << std::endl << "--- Test Presidential Form ---" << std::endl;
		PresidentialPardonForm presi("presi");
		Bureaucrat	Harry("Harry", 150);
		Bureaucrat	Ron("Ron", 1);
		std::cout << presi << Harry << Ron;
		Harry.executeForm(presi);
		Ron.executeForm(presi);
		Harry.signForm(presi);
		Ron.signForm(presi);
		Harry.executeForm(presi);
		Ron.executeForm(presi);
	} */
}
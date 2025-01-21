/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:19:16 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/17 18:36:09 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		// Create forms with valid grades
		Form form1("Form1", 3, 5);
		Form form2("Form2", 1, 1);

		// Create bureaucrats with different grades
		Bureaucrat john("John", 2);
		Bureaucrat jane("Jane", 2);

		// Test signing forms
		john.signForm(form1);  // Should succeed
		jane.signForm(form1);  // Should fail with GradeTooLowException

		// Check the status of the forms
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		// Attempt to create a form with too high a grade
		try
		{
			Form invalidForm("InvalidForm", 0, 5);  // Should throw GradeTooHighException
		}
		catch (const Form::GradeTooHighException& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		// Attempt to create a form with too low a grade
		try
		{
			Form invalidForm("InvalidForm", 151, 5);  // Should throw GradeTooLowException
		}
		catch (const Form::GradeTooLowException& e)
		{
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}

		// Test signing a form with a bureaucrat of exactly the required grade
		Bureaucrat perfect("Perfect", 1);
		perfect.signForm(form2);  // Should succeed

	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}
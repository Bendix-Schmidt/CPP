/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:07:19 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/17 18:37:06 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//member function
void	Form::beSigned(Bureaucrat bureaucrat)
{
	if ((bureaucrat.getGrade() <= sign_grade) && issigned == false)
		issigned = true;
	else
		throw GradeTooLowException();
}

//getter-functions
std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIssigned() const
{
	return (this->issigned);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->exec_grade);
}

//output-stream
std::ostream	&operator<<(std::ostream &os, Form const &form)
{
	os << form.getName()
		   << " is " << (form.getIssigned() ? "signed. " : "not signed. ")
		   << "Required sign grade: " << form.getSignGrade()
		   << " Required execute grade: " << form.getExecGrade()
		   << std::endl;
	return (os);
}

//exceptions
const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high for signing_grade or execution_grade";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low for signing_grade or execution_grade";
}

//default constructor
Form::Form() : name("new_form"), issigned(false), sign_grade(150), exec_grade(150)
{}

//standard constructor
Form::Form(std::string name, bool issigned, int sign_grade, int exec_grade):
	name(name), issigned(issigned), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

//standard constructor that sets issigned to false by default
Form::Form(std::string name, int sign_grade, int exec_grade):
	name(name), issigned(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

//copy constructor
Form::Form(const Form &original):
	name(original.name), issigned(original.issigned), sign_grade(original.sign_grade),
	exec_grade(original.exec_grade)
{
}

//copy assignment operator
Form &Form::operator=(const Form &original)
{
	if (this != &original)
	{
		this->issigned = original.issigned;
	}
	return (*this);
}

//destructor
Form::~Form()
{
}
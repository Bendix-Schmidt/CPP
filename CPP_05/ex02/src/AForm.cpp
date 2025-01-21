/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:07:19 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:00:22 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//member function
void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIssigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > exec_grade)
		throw AForm::GradeTooLowException();
	getExecuted();
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if ((bureaucrat.getGrade() <= sign_grade) && issigned == false)
		issigned = true;
	else
		throw GradeTooLowException();
}

//getter-functions
std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIssigned() const
{
	return (this->issigned);
}

int	AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int	AForm::getExecGrade() const
{
	return (this->exec_grade);
}

//output-stream
std::ostream	&operator<<(std::ostream &os, AForm const &form)
{
	os << form.getName()
		   << " is " << (form.getIssigned() ? "signed. " : "not signed. ")
		   << "Required sign grade: " << form.getSignGrade()
		   << " Required execute grade: " << form.getExecGrade()
		   << std::endl;
	return (os);
}

//exceptions
const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

//default constructor
AForm::AForm() : name("new_form"), issigned(false), sign_grade(150), exec_grade(150)
{}

//standard constructor
AForm::AForm(std::string name, bool issigned, int sign_grade, int exec_grade):
	name(name), issigned(issigned), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

//standard constructor that sets issigned to false by default
AForm::AForm(std::string name, int sign_grade, int exec_grade):
	name(name), issigned(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

//copy constructor
AForm::AForm(const AForm &original):
	name(original.name), issigned(original.issigned), sign_grade(original.sign_grade),
	exec_grade(original.exec_grade)
{
}

//copy assignment operator
AForm &AForm::operator=(const AForm &original)
{
	if (this != &original)
	{
		this->issigned = original.issigned;
	}
	return (*this);
}

//destructor
AForm::~AForm()
{
}
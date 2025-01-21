/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:19:11 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/17 16:53:13 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//member functions
void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	else
		grade = grade + 1;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	else
		grade = grade - 1;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

//exceptions:
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

//outstream
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

//default constructor
Bureaucrat::Bureaucrat() : name("random Bureaucrat"), grade(75)
{
}

//standard constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
}

//copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &original) : name(original.name), grade(original.grade)
{
}

//copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
    if (this != &original)
	{
        // Name is const, so it cannot be assigned
        this->grade = original.grade;
    }
    return (*this);
}

//destructor
Bureaucrat::~Bureaucrat()
{
}
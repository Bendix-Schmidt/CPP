/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:18:53 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/17 16:59:10 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		//member functions
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);
		
		//getters
		std::string		getName() const;
		int				getGrade() const;

		//classes to handle exceptions using Bureaucrat::GradeTooHighException
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		//constructors and destructors
		//default constructor
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		//copy constructor
		Bureaucrat(const Bureaucrat &original);
		//copy assignment operator
		Bureaucrat &operator=(const Bureaucrat &original);
		//default destructor
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);		
#endif // BUREAUCRAT_HPP
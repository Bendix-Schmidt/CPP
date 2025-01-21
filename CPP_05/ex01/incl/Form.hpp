/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:03:26 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/17 18:30:13 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string name;
		bool	issigned;
		const	int sign_grade;
		const	int exec_grade;
	
	public:
		//member functions
		void	beSigned(Bureaucrat bureaucrat);
	
		//getters
		std::string		getName() const;
		bool			getIssigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		//default constructor
		Form();
		//standard constructor
		Form(std::string name, bool issigned, int sign_grade, int exec_grade);
		//standard constructor thats sets form to unsigned by default
		Form(std::string name, int sign_grade, int exec_grade);
		//copy constructor
		Form(const Form &original);
		//copy assignment operator
		Form &operator=(const Form &original);
		//destructor
		~Form();
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);		

#endif // FORM_HPP
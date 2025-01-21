/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:03:26 by bschmidt          #+#    #+#             */
/*   Updated: 2025/01/21 15:51:50 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		//attributes
		const	std::string name;
		bool				issigned;
		const	int 		sign_grade;
		const	int 		exec_grade;
	
	public:
		//member functions/methods
		void			beSigned(Bureaucrat bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	getExecuted() const = 0;
	
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		//default constructor
		AForm();
		//standard constructor
		AForm(std::string name, bool issigned, int sign_grade, int exec_grade);
		//standard constructor thats sets form to unsigned by default
		AForm(std::string name, int sign_grade, int exec_grade);
		//copy constructor
		AForm(const AForm &original);
		//copy assignment operator
		AForm &operator=(const AForm &original);
		//destructor
		~AForm();
};

std::ostream	&operator<<(std::ostream &stream, AForm const &form);	

#endif // AFORM_HPP
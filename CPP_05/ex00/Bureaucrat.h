/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:18:53 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/18 19:28:30 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		//member functions
		void increment_grade();
		void decrement_grade();
		
		//getters
		std::string			get_name() const;
		int					get_grade() const;

		//classes to handle exceptions using Bureaucrat::GradeTooHighException
		class GradeTooHigh : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class GradeTooLow : public std::exception
		{
			virtual const char *what() const throw();
		};

		//constructors and destructors
		//default constructor
		Bureaucrat();
		Bureaucrat(const std::string name);
		//copy constructor
		Bureaucrat(const Bureaucrat &bureaucrat);
		//copy assignment operator
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		//default destructor
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);		
#endif // BUREAUCRAP_HPP
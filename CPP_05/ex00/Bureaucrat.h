/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:18:53 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/10 13:03:22 by bschmidt         ###   ########.fr       */
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
				
		};
		
		class GradeTooLow : public std::exception
		{
			
		};

		//constructors and destructors
		//default constructor
		Bureaucrat(const std::string name);
		//copy constructor
		Bureaucrat(const Bureaucrat &bureaucrat);
		//copy assignment operator
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		//default destructor
		~Bureaucrat();
}

#endif // BUREAUCRAP_HPP
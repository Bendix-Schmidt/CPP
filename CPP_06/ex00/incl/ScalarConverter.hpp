/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:47:39 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/25 15:57:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <regex.h>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cmath>

enum e_type
{
	NONUM,
	POSINF,
	NEGINF,
	CHAR,
	UNDEF,
	INT,
	FLOAT,
	DOUBLE
};

class	ScalarConverter
{
	//public convert memberfunction/method to call from outside
	public:
		static	void	convert(const std::string &literal);
		static	bool	checkFormat(std::string literal, const std::string pattern);
		static void		convertChar(const std::string literal);
		static void		convertInt(const std::string literal);
		static void		convertFloat(const std::string literal);
		static void		convertDouble(const std::string literal);
		static bool		isNullString(const std::string literal);
		static void		printConversions(char c, int i , float f, double d, std::string literal);

	//private constrcutors to achieve that class is not instanciable by users.
	//simply setting method to = 0 doesnt work because abstract methods cant be virtual 
	private:
		//attribute
		static e_type type;

		//getter-function
		static e_type getType(const::std::string &literal);

		//default constructor
		ScalarConverter();
		//copy constructor
		ScalarConverter(const ScalarConverter &original);
		//copy assignment operator
		ScalarConverter &operator=(const ScalarConverter &original);
		//destructor
		~ScalarConverter();
};

std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter);

#endif // ScalarConverter_HPP
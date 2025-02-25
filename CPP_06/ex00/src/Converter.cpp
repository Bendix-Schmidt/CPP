/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:12:04 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/20 13:34:34 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

e_type ScalarConverter::type = UNDEF;

//member functions
e_type ScalarConverter::getType(const std::string &literal)
{
	e_type type = UNDEF;
	if (literal == "nan" || literal == "nanf")
		return (NONUM);
	else if (literal == "+inf" || literal == "+inff")
		return (POSINF);
	else if (literal == "-inf" || literal == "-inff")
		return (NEGINF);
	else if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (CHAR);
	else if (check_format(literal, ""))
	return (type);
}

//constrcutors
//default constructor
ScalarConverter::ScalarConverter()
{}
//copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &original)
{
	*this = original;
}
//copy assignment operator
ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &origin)
{
	if (this != &origin)
		return (*this);
	//no need to set e_type. Since it is static, all instances of ScalarConverter have the same type
	return (*this);
}
//destructor
ScalarConverter::~ScalarConverter()
{}

//outstream:
std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter)
{
	(void) scalarconverter;
	stream << "Scalar Converter" << std::endl;
	return (stream);
}

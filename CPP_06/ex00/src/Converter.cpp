/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:12:04 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/01/20 18:17:55 by bendixschmi      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Converter.hpp"






//outstream:
std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter)
{
	(void) scalarconverter;
	stream << "Scalar Converter" << std::endl;
	return (stream);
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
	return (*this);
}
//destructor
~ScalarConverter()
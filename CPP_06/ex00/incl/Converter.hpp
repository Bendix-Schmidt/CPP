/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:47:39 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/09 14:51:58 by bendixschmi      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

enum e_type
{
	UNDEF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONUM,
	POSINF,
	NEGINF
};

class	ScalarConverter
{
	//public convert memberfunction/method to call from outside
	public:
		static void convert(const std::string &literal);

	//private constrcutors to achieve that class is not instanciable by users.
	//simply setting method to = 0 doesnt work because abstract methods cant be virtual 
	private:
		//attribute
		static e_type type;

		//getter-function
		static e_type getType(const::std::string &literal);

		//default constructor
		ScalarConverter()
		//copy constructor
		ScalarConverter(const ScalarConverter &original)
		//copy assignment operator
		ScalarConverter &operator=(const ScalarConverter &original)
		//destructor
		~ScalarConverter()
};


std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter);

#endif // ScalarConverter_HPP
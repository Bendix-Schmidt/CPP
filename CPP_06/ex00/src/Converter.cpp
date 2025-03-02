/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:12:04 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/03/02 13:12:01 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_type ScalarConverter::type = UNDEF;

//member functions

void	ScalarConverter::convert(const std::string &literal)
{
	type = getType(literal);
	switch(type)
	{
		case NONUM:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break ;
		case POSINF:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			break ;
		case NEGINF:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break ;
		case CHAR:
			convertChar(literal);
			break ;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break ;
		case DOUBLE:
			convertDouble(literal);
			break ;
		case UNDEF:
			std::cout << "Error: Not possible to assign a type to this literal" << std::endl;
	}
}

void	ScalarConverter::convertChar(const std::string literal)
{
	char	c = static_cast<char>(literal[0]);
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);
	printConversions(c, i, f, d, literal);
}
void	ScalarConverter::convertInt(const std::string literal)
{
	int 		i = atoi(literal.c_str());
	long long	num = atoll(literal.c_str());

	if (num > static_cast<long long>(INT_MAX) || num < static_cast<long long>(INT_MIN))
		printConversions(0, 0, 0, 0, literal);
	else
	{
		char	c = static_cast<char>(i);
		float	f = static_cast<float>(i);
		double	d = static_cast<double>(i);
		printConversions(c, i, f, d, literal);
	}
}
void	ScalarConverter::convertFloat(const std::string literal)
{
	float		f = strtof(literal.c_str(), NULL);
	int			i = static_cast<int>(f);
	char		c = static_cast<char>(f);
	double		d = static_cast<double>(f);
	printConversions(c, i, f, d, literal);
}
void	ScalarConverter::convertDouble(const std::string literal)
{
	double		d = strtod(literal.c_str(), NULL);
	float		f = static_cast<float>(d);
	int			i = static_cast<int>(d);
	char		c = static_cast<char>(d);
	printConversions(c, i, f, d, literal);
}

void	ScalarConverter::printConversions(char c, int i, float f, double d, std::string literal)
{
	//char:
	if ((static_cast<int>(c) == 0 && !isNullString(literal)) || static_cast<int>(d) < 0 || static_cast<int>(d) > 255)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<int>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	//int:
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()) || (i == 0 && !isNullString(literal)))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	//float:
	std::cout << "float: ";
	if (std::isnan(static_cast<double>(f)) || (f == static_cast<double>(0) && !isNullString(literal)))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << f;
		if (static_cast<int>(f) == f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	
	//double:
	std::cout << "double: ";
	if (std::isnan(d) || (d == static_cast<double>(0) && !isNullString(literal)))
		std::cout << " impossible " << std::endl;
	else
	{
		std::cout << d;
		if (static_cast<int>(d) == d)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

bool	ScalarConverter::isNullString(const std::string str)
{
	if (str == "0" || str == "0.0" || str == "0.0f" || str == "-0" || str == "-0.0" || str == "-0.0f")
		return (true);
	return (false);
}


bool	ScalarConverter::checkFormat(std::string literal, const std::string pattern)
{
	regex_t regex;
	bool	match = false; //needed because compiled regular expression has to be freed before returning true or false
	
	if (regcomp(&regex, pattern.c_str(), REG_EXTENDED) != 0)
	{
		std::cerr << "Regex compilation failed" << std::endl;
		return (match);
	}
	
	if (regexec(&regex, literal.c_str(), 0, NULL, 0) == 0)
		match = true;

	regfree(&regex);
	return (match);
}

e_type	ScalarConverter::getType(const std::string &literal)
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
	else if (checkFormat(literal, "^[+-]?[0-9]+$"))
		return (INT);
	else if (checkFormat(literal, "^[+-]?[0-9]+\\.[0-9]+f$"))
		return (FLOAT);
	else if (checkFormat(literal, "^[+-]?[0-9]+\\.[0-9]+$"))
		return (DOUBLE);
	return (type);
}

//constrcutors
//default constructor
ScalarConverter::ScalarConverter()
{}
//copy constructor and copy assignment operator not defined (implemented to assure that class can not be instantiated)

//destructor
ScalarConverter::~ScalarConverter()
{}

//outstream (kinda useless):
std::ostream	&operator<<(std::ostream &stream, ScalarConverter const &scalarconverter)
{
	(void) scalarconverter;
	stream << "ScalarConverter" << std::endl;
	return (stream);
}

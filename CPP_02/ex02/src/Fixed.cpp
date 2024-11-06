/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:22:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/06 17:52:27 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fp_nb_val = 0;
}

//Copy Constructor
Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = original;
}

//int constructor
Fixed::Fixed(const int x)
{
	std::cout << "Int Constructor called" << std::endl;
	fp_nb_val = x << bits;
}

//float constructor
Fixed::Fixed(const float x)
{
	std::cout << "Float Constructor called" << std::endl;
	fp_nb_val = roundf(x * (1 << bits));
}

//Assignment operator
Fixed	&Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &original)
        fp_nb_val = original.getRawBits();
	return (*this);
}

//Arithmetic Operators:
		Fixed operator+(const Fixed &rhs) const;
   		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
   		Fixed operator/(const Fixed &rhs) const;















//convert to float Function
float	Fixed::toFloat(void) const
{
	return (static_cast<float>( this->getRawBits() ) / ( 1 << this->bits ));
}

//convert to int function
int		Fixed::toInt(void) const
{
	return (fp_nb_val >> bits);
}

//get bit-value function
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fp_nb_val);
}

//set bit-value function
void	Fixed::setRawBits(int const raw)
{
	fp_nb_val = raw;
}

//default deconstructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//outstream << operator overload
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:22:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/06 19:44:59 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed()
{
	fp_nb_val = 0;
}

//Copy Constructor
Fixed::Fixed(const Fixed &original)
{
	*this = original;
}

//int constructor
Fixed::Fixed(const int x)
{
	fp_nb_val = x << bits;
}

//float constructor
Fixed::Fixed(const float x)
{
	fp_nb_val = roundf(x * (1 << bits));
}

//Assignment operator
Fixed	&Fixed::operator=(const Fixed& original)
{
	if (this != &original)
        fp_nb_val = original.getRawBits();
	return (*this);
}

//Arithmetic Operators (the "this->" is optional, but easier to understand):
Fixed Fixed::operator+(const Fixed &second) const
{
	return (Fixed(this->toFloat() + second.toFloat()));
}

Fixed Fixed::operator-(const Fixed &second) const
{
	return (Fixed(this->toFloat() - second.toFloat()));
}

Fixed Fixed::operator*(const Fixed &second) const
{
	return (Fixed(this->toFloat() * second.toFloat())); 
}

Fixed Fixed::operator/(const Fixed &second) const
{
	return (Fixed(this->toFloat() / second.toFloat())); 
}

//Increment and Decrement operators (int in brackets means its post-increment/decrement):
Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++(this->fp_nb_val);
	return (tmp);
}
		
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--(this->fp_nb_val);
	return (tmp);
}

Fixed Fixed::operator++(void)
{
	this->fp_nb_val += 1;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->fp_nb_val -= 1;
	return (*this);
}

//MIN and MAX functions
Fixed& Fixed::min(Fixed &first, Fixed &second)
{
    if (first.getRawBits() > second.getRawBits())
        return (second);
	else
        return (first);
}

Fixed& Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first.getRawBits() > second.getRawBits())
        return ((Fixed&)second);
	else
        return ((Fixed&)first);
}

Fixed& Fixed::max(Fixed &first, Fixed &second)
{
    if (first.getRawBits() > second.getRawBits())
        return (first);
	else
        return (second);
}

Fixed& Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first.getRawBits() > second.getRawBits())
        return ((Fixed&)first);
	else
        return ((Fixed&)second);
}

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
}

//outstream << operator overload
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

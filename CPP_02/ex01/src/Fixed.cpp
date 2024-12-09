/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:22:49 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/07 18:57:02 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fp_nb_val = 0;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int Constructor called" << std::endl;
	fp_nb_val = x << bits;
}

Fixed::Fixed(const float x)
{
	std::cout << "Float Constructor called" << std::endl;
	fp_nb_val = roundf(x * (1 << bits));
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = original;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>( this->getRawBits() ) / ( 1 << this->bits ));
}

int		Fixed::toInt(void) const
{
	return (fp_nb_val >> bits);
}

Fixed	&Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &original)
        fp_nb_val = original.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (fp_nb_val);
}

void	Fixed::setRawBits(int const raw)
{
	fp_nb_val = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
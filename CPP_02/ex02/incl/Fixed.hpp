/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:23:15 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/06 17:07:06 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					fp_nb_val;
		static	const int	bits = 8;
	
	public:
		Fixed();
		~Fixed();


		//copy constructor
		Fixed(const Fixed& original);
		
		//int constructor
		Fixed(const int value);

		//float constructor
		Fixed(const float value);

		//Operator overload:
		//Assignment operator:
		Fixed &operator=(const Fixed &original);

		//Arithmetic Operators:
		Fixed operator+(const Fixed &rhs) const;
   		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
   		Fixed operator/(const Fixed &rhs) const;

		//Comparison operators:
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		//Increment and Decrement operators:
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator++(void);
		Fixed operator--(void);
		
		//MIN and MAX functions
		static	Fixed& min(Fixed &first, Fixed &second);
		static	Fixed& min(const Fixed &first, const Fixed &second);
		static	Fixed& max(Fixed &first, Fixed &second);
		static	Fixed& max(const Fixed &first, const Fixed &second);

		//functions:
		int		getRawBits ( void ) const;
		void	setRawBits ( int const raw_bit );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif // FIXED_HPP
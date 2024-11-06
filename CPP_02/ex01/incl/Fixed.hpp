/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:23:15 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/05 19:33:06 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
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

		//copy assignment operator
		Fixed &operator=(const Fixed &original);

		//functions:
		int		getRawBits ( void ) const;
		void	setRawBits ( int const raw_bit );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif // FIXED_HPP
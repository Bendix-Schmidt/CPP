/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:23:15 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/05 18:29:32 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class	Fixed
{
	private:
		int					fp_nb_val;
		static	const int	bits = 8;
	
	public:
		Fixed();
		~Fixed();


		//copy constructor
		Fixed(Fixed& original);
		
		//copy assignment operator
		Fixed& operator=(Fixed& original);


		int		getRawBits ( void ) const;
		void	setRawBits ( int const raw_bit );
};

#endif // FIXED_HPP
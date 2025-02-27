/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:46:37 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/27 15:02:48 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
	T	*array;
	int	length;
	
	public:
	//methods
	int size();

	//exceptions
	class IndexOutOfBounds : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: index is out of bounds");
		}
	};

	//overload
	T	&operator[](const int n);
	
	//Constructor:
	Array();
	Array(unsigned int n);
	Array(const Array &array);
	Array &operator=(const Array &array);
	~Array();
};

#include "Array.tpp"

#endif // ARRAY_HPP


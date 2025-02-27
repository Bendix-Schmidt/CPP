/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:06:11 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/26 20:15:01 by bendixschmi      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
	T	*array;
	int	size;
	
	public:
	//methods
	int size();

	//exceptions
	class IndexOutOfBounds : public std::exception
	{
		public:
		virtual const char *what() const throw()
	}

	//overload
	T	&operator[](const int n);
	
	//Constructor:
	Array();
	Array(unsigned int n);
	Array(const Array &array);
	Array &operator=(const Array &array);
	~Array();

	#include "Array.tpp"
};

#endif // ARRAY_HPP
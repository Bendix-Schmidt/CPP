/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:16:07 by bendixschmi       #+#    #+#             */
/*   Updated: 2025/02/27 14:57:18 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//methods
template <typename T>
int Array<T>::size()
{
	return (this->length);
}

//overload
template <typename T>
T &Array<T>::operator[](const int n)
{
	if (n < 0 || n >= this->length)
		throw typename Array<T>::IndexOutOfBounds();
	else
		return (array[n]);
}

//constructors
//default
template <typename T>
Array<T>::Array(): array(NULL), length(0) {}

//standard
template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]), length(n){}

//copy constructor
template <typename T>
Array<T>::Array(const Array &original) : array(new T[original.length]), length(original.length)
{	
	for (int i = 0; i < length; i++)
		array[i] = original.array[i];
}

//copy assignment operator
template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &original)
{
	if (this != &original)
	{
		delete [] this->array;
		this->length = original.length;
		this->array = new T[original.length];
		for (int i = 0; i < original.length; i++)
			this->array[i] = original.array[i];
	}
	return (*this);
}

//destructor
template <typename T>
Array<T>::~Array()
{
	delete [] (this->array);
}


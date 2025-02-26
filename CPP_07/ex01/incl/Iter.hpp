/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:05:16 by bschmidt          #+#    #+#             */
/*   Updated: 2025/02/26 16:18:51 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

template <typename T>
void printArray(T &a)
{
	std::cout << a << std::endl;
}

template <typename T>
void incrementArray(T &a)
{
	a = a+1;
}

#endif // ITER_HPP
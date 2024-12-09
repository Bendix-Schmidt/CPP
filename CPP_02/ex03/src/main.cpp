/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:22:39 by bschmidt          #+#    #+#             */
/*   Updated: 2024/12/09 13:29:07 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(3.0f, 2.0f);
	Point	b(7.0f, 14.0f);
	Point	c(10.0f, 5.0f);

	std::cout << "Trianlge:" << std::endl
			  <<  "A: " << a << std::endl
			  <<  "B: " << b << std::endl
			  <<  "C: " << c << std::endl << std::endl;

	{
		Point	point1(5, 5);
		if (bsp(a, b, c, point1))
			std::cout << point1 << " lies in triangle" << std::endl;
		else 
			std::cout << point1 << " does not lie in triangle" << std::endl;
	}
	{
		Point	point2(17.0f, 6.5f);
		if (bsp(a, b, c, point2))
			std::cout << point2 << " lies in triangle" << std::endl;
		else 
			std::cout << point2 << " does not lie in triangle" << std::endl;
	}
	{
		Point	point3(7.5f, 5.5f);
		if (bsp(a, b, c, point3))
			std::cout << point3 << " lies in triangle" << std::endl;
		else 
			std::cout << point3 << " does not lie in triangle" << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:22:39 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/11 18:20:10 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(3.0f, 0.0f);
	Point	c(1.5f, 3.0f);
	Point	point1(2.0f, 2.0f);
	
	
	if (bsp(a,b,c, point1))
		printf("The point lies inside the triangle.");
	else
		printf("The point lies outside the triangle."); 
}

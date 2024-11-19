/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:59 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/19 17:26:28 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed get_triangle(Point const a, Point const b, Point const c)
{
	Fixed area = Fixed(0.5f) * 
						a.get_x() * (b.get_y() - c.get_y()) +
						b.get_x() * (c.get_y() - a.get_y()) +
						c.get_x() * (a.get_y() - b.get_y());
	if (area < 0)
		area = area * (-1);
	return (area);
}

bool	bsp2(Point const point)
{
	Fixed one_point_y = point.get_y();
	float y_as_float = one_point_y.toFloat();
	printf("Y-value as float: %f\n", y_as_float);

	Fixed one_point_x = point.get_x();
	float x_as_float = one_point_x.toFloat();
	printf("x-value as float: %f\n", x_as_float);
	return (true);
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	whole_triangle = get_triangle(a, b, c);
	Fixed	part_triangle1 = get_triangle(a, b, point);
	Fixed	part_triangle2 = get_triangle(a, c, point);
	Fixed	part_triangle3 = get_triangle(b, c, point);

	float x = part_triangle1.toFloat();
	printf("T1: %f\n", x);
	x = part_triangle2.toFloat();
	printf("T2: %f\n", x);
	x = part_triangle3.toFloat();
	printf("T3: %f\n", x);
	x = whole_triangle.toFloat();
	printf("T: %f\n", x);

	if (part_triangle1 == 0 || part_triangle1 == 0 || part_triangle3 == 0)
		return (false);
	else if ((part_triangle1 + part_triangle2 + part_triangle3) == whole_triangle)
		return (true);
	else
		return (false);
	return (true);
}
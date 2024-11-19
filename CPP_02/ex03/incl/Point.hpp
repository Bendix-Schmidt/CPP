/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:48:48 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/11 18:55:11 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp" //include Fixed header to have Fixed objects as members

class Point
{
	private:
	const Fixed x;
	const Fixed y;
	
	public:
	Point();
	~Point();
	
	Point(const float x_value, const float y_value);
	Point(const Point &original);
	Point &operator=(const Point &original);

	Fixed get_x() const;
	Fixed get_y() const;
};

bool 			bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream 	&operator<<(std::ostream &o, Point const &i);

#endif // POINT_HPP
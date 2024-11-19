/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:44:54 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/11 18:56:01 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{}

Point::Point(const float x_value, const float y_value) : x(Fixed(x_value)), y(Fixed(y_value))
{}

Point::Point(const Point &original)
{
	*this = original;
}

Point	&Point::operator=(const Point &original)
{
	if (this == &original)
		return (*this);
	return (*this);
	//really dumb and confusing. Assignment operator makes 0 sense here:
	//usually, ater making sure you dont already have the same object, you start assigning the values
	//from the original to the "copy-to-be". This is not possible here, because of const values...
	//--> stooopid, why do we even need the assignment operator then????
}

Fixed	Point::get_x(void) const
{
	return(this->x);
}

Fixed	Point::get_y(void) const
{
	return(this->y);
}

Point::~Point()
{}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:23:17 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/04 13:43:24 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float nbr1, const float nbr2) : x(nbr1), y(nbr2)
{
}

Point::Point(const Point& src) : x(src.x), y(src.y)
{
}

Point::~Point()
{
}

Fixed Point::get_x( void ) const
{
	return (x);
}

Fixed Point::get_y( void ) const
{
	return (y);
}
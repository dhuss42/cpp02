/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:21:54 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/04 15:20:50 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// calculate vectors AB and AP
	// AB = bx - ax, by - ay
// do that for every line of the triagle
// BC, BP
// CA, CA
// calculate cross product for all pairs
	// ax * by - bx * ay
// if the cross product is always positive or always negative then the point is to the left of the line (AB, BC, CA)

Fixed	cross_produkt(Point const a, Point const b, Point const p)
{
	Fixed ab_x = b.get_x() - a.get_x();
	Fixed ab_y = b.get_y() - a.get_y();
	Fixed ap_x = p.get_x() - a.get_x();
	Fixed ap_y = p.get_y() - a.get_y();

	return (ab_x * ap_y - ap_x * ab_y);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	cross_1 = cross_produkt(a, b, point);
	Fixed	cross_2 = cross_produkt(b, c, point);
	Fixed	cross_3 = cross_produkt(c, a, point);

	if ((cross_1 > 0 && cross_2 > 0 && cross_3 > 0)
		|| (cross_1 < 0 && cross_2 < 0 && cross_3 < 0))
		return (true);
	return (false);
}

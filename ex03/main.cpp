/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:22:37 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/04 15:25:14 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main()
{
	Point A(0, 0);
	Point B(4, 0);
	Point C(2, 4);
	Point P(2, 2);
	// Point P(4, 0);
	// Point P(3, 10);

	if (bsp(A, B, C, P))
		std::cout << "point is within triangle" << std::endl;
	else
		std::cout << "point is outside triangle or a corner" << std::endl;
	return (0);
}
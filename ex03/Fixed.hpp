/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:22:30 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/04 10:22:32 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int	 getRawBits( void ) const;
		void	setRawBits(int const raw);
		float   toFloat( void ) const;
		int	 toInt( void ) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed& min(Fixed& value1, Fixed& value2);
		static const Fixed& min(const Fixed& value1, const Fixed& value2);
		static Fixed& max(Fixed& value1, Fixed& value2);
		static const Fixed& max(const Fixed& value1, const Fixed& value2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);

// copy constructor
// there is a default copy constructor
// copy constructed is called when object is created from an existing object

// copy assignment operator
// called When an existing object is assigned the value of another existing object

//fract bits
// in fixed-point system a number is scaled by 2^fract_bits
// when displaying the values it is divided by 2^fract_bits to retrieve the actual num
// 2^8 = 256
// 3.25 x 256 = 832
// -> fixed precision (no floating point errors)
// -> speed (less complex therefore faster)
// -> memory efficient (uses ints which are easier to store and manipulate than floats)
#endif
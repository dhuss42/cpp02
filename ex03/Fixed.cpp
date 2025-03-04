/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:22:15 by dhuss             #+#    #+#             */
/*   Updated: 2025/03/04 10:22:16 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

//-------constructos and destructor---------//

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int n)
{
    this->value = n << fract_bits;
}

Fixed::Fixed(const float n)
{
    this->value = roundf(n * (1 << fract_bits));
}

Fixed::Fixed(const Fixed& f) : value(f.value)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if(this != &other)
    {
        this->value = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
}

//-------getters and setters---------//

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

int Fixed::getRawBits( void ) const
{
    return (value);
}

//-------conversion functions---------//

int Fixed::toInt( void ) const
{
    return (value >> fract_bits);
}

float Fixed::toFloat( void ) const
{
     return (static_cast<float>(value) / (1 << fract_bits));
}

//-------overloaded comparison operators---------//

bool    Fixed::operator>(const Fixed& other) const
{
    return (this->value > other.value);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (this->value >= other.value);
}

bool    Fixed::operator<(const Fixed& other) const
{
    return (this->value < other.value);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return (this->value <= other.value);
}

bool    Fixed::operator==(const Fixed& other) const
{
    return (this->value == other.value);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return (this->value != other.value);
}

//-------arithmetic operators---------//

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->value + other.value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->value - other.value);
    return (result);
}

/* due to multiplcation the result is double scaled by 2^fractbits
which is why we need to shift to the right to get the single scaled result
When we multiply two fixed-point numbers, we shift right because the result is too large*/
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    result.setRawBits((this->value * other.value) >> fract_bits);
    return (result);
}

/* A = 10 (2560)
   B = 2 (512)
    2560 / 512 = 5 (value is not scaled)
    that is why first value is scaled up
    2560 << 8 = 655360
    655360 / 512 = 1280
    1280 / 256 = 5.0
 When we divide, the opposite happens: the result is too small, so we shift left before dividing*/
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;

    result.setRawBits((this->value << fract_bits) / other.value);
    return (result);
}

//-------increment and decrement operators---------//

Fixed& Fixed::operator++()
{
    value++;
    return (*this);
}

/* post-increment operator
int parameter is a dummy that only serves to distinguish pre- and postincrement
not returning by reference since we want the old state of the object and
incrementing after returning
*/
Fixed Fixed::operator++(int)
{
    Fixed old = *this;

    value++;
    return (old);
}

Fixed& Fixed::operator--()
{
    value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;

    value--;
    return (old);
}

//-------min and max member functions---------//

Fixed& Fixed::min(Fixed& value1, Fixed& value2)
{
    if (value1 >= value2)
        return (value2);
    else
        return (value1);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
    if (value1 >= value2)
        return (value2);
    else
        return (value1);
}

 Fixed& Fixed::max(Fixed& value1, Fixed& value2)
{
    if (value1 >= value2)
        return (value1);
    else
        return (value2);
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
    if (value1 >= value2)
        return (value1);
    else
        return (value2);
}

//-------outside class functions---------//

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return (os);
}

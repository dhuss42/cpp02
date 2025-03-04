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

Point& Point::operator=(const Point& other)
{
    if (this != &other)
    {
        this->x = other.get_x();
        this->y = other.get_y();
    }
    return (*this);
}

const Fixed Point::get_x( void ) const
{
    return (x);
}

const Fixed Point::get_y( void ) const
{
    return (y);
}
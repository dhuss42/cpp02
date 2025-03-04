#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float nbr1, const float nbr2);
        Point(const Point& src);
        Point& operator=(const Point& other);
        ~Point();
        const Fixed get_x( void ) const;
        const Fixed get_y( void ) const;
};

#endif
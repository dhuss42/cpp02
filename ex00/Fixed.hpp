#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int fract_bits;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits(int const raw);
};

// copy constructor
// there is a default copy constructor
// copy constructed is called when object is created from an existing object

// copy assignment operator
// called When an existing object is assigned the value of another existing object

#endif
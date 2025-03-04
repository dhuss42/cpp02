#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

/* Default constructor */
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*  Int constructor
2^x = 1 << x
2^x is power of 2 meaning always a 1 followed by 0 in binary
when you shift 1 by x it becomes a representation of the power of 2
1 << 0 -> 00000001 = 1
1 << 3 -> 00001000 = 8
*/
Fixed::Fixed(const int n)
{
    this->value = n << fract_bits;
    std::cout << "Int constructor called" << std::endl;
}

/* Float constructor
 roundf rounds to x to the nearest int
 same bit shifting operation as before
*/
Fixed::Fixed(const float n)
{
     this->value = roundf(n * (1 << fract_bits));
     std::cout << "Float constructor called" << std::endl;
}
/* Copy Constructor */
Fixed::Fixed(const Fixed& f) : value(f.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator
// returns a reference to the current object
// operator= is the overloaded assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other) // need incase of self assignment (a = a)
    {
        this->value = other.getRawBits();
    }
    return (*this); // returns the current object by reference
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

int Fixed::getRawBits( void ) const
{
    return (value);
}

int Fixed::toInt( void ) const
{
    return (value >> fract_bits);
}

/* 
    need to typecast to float to be able to retrive decimal values
    static_cast is safer then (float)
    shift bits to left to properly convert back 1 << 8 = 256
    divide to get the orignal value
 */
float Fixed::toFloat( void ) const
{
     return (static_cast<float>(value) / (1 << fract_bits));
}

/* 
    goal: tell compiler how do handle this - std::cout << fixed.value;
    inserts converted float-value into output stream
 */
std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return (os);
}

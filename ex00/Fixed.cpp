#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : value(f.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

// returns a reference tothe current object
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
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

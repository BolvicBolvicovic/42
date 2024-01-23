#include "Fixed.hpp"
#include <iostream>


const int			Fixed::sizeOfFractionedBits = 0;
Fixed::Fixed()			: fixedNumber(0)
{ std::cout << "Default constructor called" << std::endl; }
Fixed::Fixed(Fixed &newNumber)	: fixedNumber(newNumber.fixedNumber)
{ std::cout << "Copy constructor called" << std::endl; }
Fixed::~Fixed()
{ std::cout << "Destructor called" << std::endl; }
	
Fixed		&Fixed::operator=( const Fixed &other )
{ std::cout << "Copy assignment operator called" << std::endl; if (this != &other) {this->fixedNumber = other.fixedNumber;} return *this; }
int		Fixed::getRawBits( void ) const		{ { std::cout << "getRawBits member function called" << std::endl; }return fixedNumber; }
void		Fixed::setRawBits( int const raw )	{ this->fixedNumber = raw; }

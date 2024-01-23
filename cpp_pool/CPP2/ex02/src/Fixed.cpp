#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed()			: fixedNumber(0)
{ std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( const Fixed &newNumber)	: fixedNumber(newNumber.fixedNumber)
{ std::cout << "Copy constructor called" << std::endl; }

Fixed::~Fixed()
{ std::cout << "Destructor called" << std::endl; }

Fixed::Fixed( const int intToFix )
{ this->fixedNumber = intToFix * (1 << this->sizeOfFractionalBits); }

Fixed::Fixed( const float floatToFix )
{ this->fixedNumber = roundf(floatToFix * (1 << this->sizeOfFractionalBits)); }

// Overflowed operators
Fixed		&Fixed::operator=( const Fixed &other )
{	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) { this->fixedNumber = other.fixedNumber; } 
	return *this;
}
std::ostream	&operator<<( std::ostream &os, const Fixed &fixed )
{ os << fixed.toFloat(); return os; }

// Public Methods
int		Fixed::getRawBits( void ) const	
{ std::cout << "getRawBits member function called" << std::endl; return fixedNumber; }

void		Fixed::setRawBits( int const raw )
{ this->fixedNumber = raw; }

float		Fixed::toFloat( void ) const
{ return static_cast<float>(this->fixedNumber) / (1 << this->sizeOfFractionalBits); }

int		Fixed::toInt( void )	const
{ return this->fixedNumber / (1 << this->sizeOfFractionalBits); }

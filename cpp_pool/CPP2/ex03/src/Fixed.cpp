/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:17:51 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/23 19:18:09 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed()				: fixedNumber(0) {}
Fixed::Fixed( const Fixed &newNumber)	: fixedNumber(newNumber.fixedNumber) {}
Fixed::~Fixed() {}

Fixed::Fixed( const int intToFix )
{ this->fixedNumber = intToFix * (1 << this->sizeOfFractionalBits); }

Fixed::Fixed( const float floatToFix )
{ this->fixedNumber = roundf(floatToFix * (1 << this->sizeOfFractionalBits)); }

// Overflowed operators
Fixed		&Fixed::operator=( const Fixed &other )
{ if (this != &other) { this->fixedNumber = other.fixedNumber; } return *this; }

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed )
{ os << fixed.toFloat(); return os; }


bool		Fixed::operator>( const Fixed &fNum ) const
{ return this->getRawBits() > fNum.getRawBits(); }

bool		Fixed::operator<( const Fixed &fNum ) const
{ return this->getRawBits() < fNum.getRawBits(); }

bool		Fixed::operator==( const Fixed &fNum ) const
{ return this->getRawBits() == fNum.getRawBits(); }

bool		Fixed::operator<=( const Fixed &fNum ) const
{ return this->getRawBits() <= fNum.getRawBits(); }

bool		Fixed::operator>=( const Fixed &fNum ) const
{ return this->getRawBits() >= fNum.getRawBits(); }

bool		Fixed::operator!=( const Fixed &fNum ) const
{ return this->getRawBits() != fNum.getRawBits(); }


Fixed		Fixed::operator+( const Fixed &fNum ) const
{ return Fixed( this->toFloat() + fNum.toFloat()); }

Fixed		Fixed::operator-( const Fixed &fNum ) const
{ return Fixed( this->toFloat() - fNum.toFloat()); }

Fixed		Fixed::operator/( const Fixed &fNum ) const
{ return Fixed( this->toFloat() / fNum.toFloat()); }

Fixed		Fixed::operator*( const Fixed &fNum ) const
{ return Fixed( this->toFloat() * fNum.toFloat()); }


Fixed& 		Fixed::operator++( void )	// prefix
{ ++this->fixedNumber; return *this; }

Fixed		Fixed::operator++( int )	// postfix
{ Fixed tmp( *this ); tmp.fixedNumber = this->fixedNumber++; return tmp; }

Fixed&		Fixed::operator--( void )	// prefix
{ --this->fixedNumber; return *this; }

Fixed		Fixed::operator--( int )	// postfix
{ Fixed tmp( *this ); tmp.fixedNumber = this->fixedNumber--; return tmp; }


// Public Methods
int		Fixed::getRawBits( void ) const	
{ return fixedNumber; }

void		Fixed::setRawBits( int const raw )
{ this->fixedNumber = raw; }

float		Fixed::toFloat( void ) const
{ return static_cast<float>(this->fixedNumber) / (1 << this->sizeOfFractionalBits); }

int		Fixed::toInt( void )	const
{ return this->fixedNumber / (1 << this->sizeOfFractionalBits); }

Fixed		Fixed::min(Fixed &a, Fixed&b)
{ if ( a.getRawBits() < b.getRawBits() ) { return a;} else {return b;} }

Fixed		Fixed::max(Fixed &a, Fixed&b)
{ if ( a.getRawBits() > b.getRawBits() ) { return a;} else {return b;} }

const Fixed	&Fixed::min(const Fixed &a, const Fixed&b)
{ if ( a.getRawBits() < b.getRawBits() ) { return a;} else {return b;} }

const Fixed	&Fixed::max(const Fixed &a, const Fixed&b)
{ if ( a.getRawBits() > b.getRawBits() ) { return a;} else {return b;} }

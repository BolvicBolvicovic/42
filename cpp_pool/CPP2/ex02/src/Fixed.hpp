#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	int			fixedNumber;
	static const int	sizeOfFractionalBits = 8;
public:
	Fixed();
	Fixed( const int intToFix			);
	Fixed( const float floatToFix			);
	Fixed( const Fixed &newNumber			);
	~Fixed();

	friend std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );
	Fixed			&operator=( const Fixed &other );
	
	bool			operator>( const Fixed &fNum ) const;
	bool			operator<( const Fixed &fNum ) const;
	bool			operator==( const Fixed &fNum ) const;
	bool			operator<=( const Fixed &fNum ) const;
	bool			operator>=( const Fixed &fNum ) const;
	bool			operator!=( const Fixed &fNum ) const;
	
	Fixed			operator+( const Fixed &fNum ) const;
	Fixed			operator-( const Fixed &fNum ) const;
	Fixed			operator/( const Fixed &fNum ) const;
	Fixed			operator*( const Fixed &fNum ) const;

	Fixed			&operator++( void ); // prefix
	Fixed			operator++( int ); // postfix
	Fixed			&operator--( void ); // prefix
	Fixed			operator--( int ); // postfix

	Fixed			&min(Fixed &a, Fixed&b);
	Fixed			&max(Fixed &a, Fixed&b);
	const Fixed		&min(const Fixed &a, const Fixed&b);
	const Fixed		&max(const Fixed &a, const Fixed&b);

	int			getRawBits( void ) 	const	;
	void			setRawBits( int const raw	);
	float			toFloat( void ) 	const	;
	int			toInt( void ) 		const	;
};

#endif

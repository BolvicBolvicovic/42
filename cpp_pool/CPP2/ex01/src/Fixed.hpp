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

	Fixed			&operator=( const Fixed &other	);

	int			getRawBits( void ) 	const	;
	void			setRawBits( int const raw	);
	float			toFloat( void ) 	const	;
	int			toInt( void ) 		const	;
};

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );

#endif

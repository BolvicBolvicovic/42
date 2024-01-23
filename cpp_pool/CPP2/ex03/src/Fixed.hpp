/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:17:56 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/23 19:18:09 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	static Fixed		min(Fixed &a, Fixed&b);
	static Fixed		max(Fixed &a, Fixed&b);
	static const Fixed	&min(const Fixed &a, const Fixed&b);
	static const Fixed	&max(const Fixed &a, const Fixed&b);

	int			getRawBits( void ) 	const	;
	void			setRawBits( int const raw	);
	float			toFloat( void ) 	const	;
	int			toInt( void ) 		const	;
};

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );
#endif

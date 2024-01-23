/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:18:05 by vcornill          #+#    #+#             */
/*   Updated: 2024/01/23 19:23:05 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_CPP

#include "Fixed.hpp"

class	Point
{
private:
	const Fixed	x;
	const Fixed	y;

public:
	Point();
	Point( const float a, const float b );
	Point( Point pt );
	~Point();

};

std::ostream	&operator<<( std::ostream &os, const Fixed &fixed );

#endif

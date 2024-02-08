/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:28:01 by vcornill          #+#    #+#             */
/*   Updated: 2024/02/08 14:12:57 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class	Animal
{
protected:
	std::string	type;
public:
	Animal( void );
	Animal( Animal &copy );
	virtual	~Animal( void );

	Animal	&operator=( const Animal &ref );

	std::string	getType( void ) const;
	void		setType( std::string str );

	virtual void	makeSound( void ) const = 0;

};
